#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct arrayptr {
   int size;
   long* arr;
} arrayptr;

static int is_blank_line(const char *s) {
    for (const char *p = s; *p; ++p) {
        if (*p != ' ' && *p != '\t' && *p != '\r' && *p != '\n') return 0;
    }
    return 1;
}

int contains(long* arr, int size, long num){
    for (int i = 0; i < size; i++){
        if (num == arr[i]){
            return 1;
        }
    }
    return 0;
}

int cmpfunc(const void* a, const void* b) {
    long arg1 = *(const long*)a;
    long arg2 = *(const long*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

typedef struct { long start, end; } Interval;

static int cmp_interval(const void *a, const void *b) {
    const Interval *A = a, *B = b;
    if (A->start < B->start) return -1;
    if (A->start > B->start) return 1;
    if (A->end < B->end) return -1;
    if (A->end > B->end) return 1;
    return 0;
}

/* Merge input ranges in first[]/second[] (length n).
 * Returns malloc'ed Interval* and sets *out_count. Caller must free().
 * Merges overlapping and contiguous ranges; change condition if you want strict non-contiguous behavior.
 */
Interval *merge_intervals(long first[], long second[], int n, int *out_count) {
    if (n <= 0) { *out_count = 0; return NULL; }

    Interval *iv = malloc(sizeof(Interval) * (size_t)n);
    if (!iv) { perror("malloc"); exit(1); }
    for (int i = 0; i < n; ++i) {
        iv[i].start = first[i];
        iv[i].end   = second[i];
        if (iv[i].end < iv[i].start) { long t = iv[i].start; iv[i].start = iv[i].end; iv[i].end = t; }
    }

    qsort(iv, n, sizeof(Interval), cmp_interval);

    int m = 0;
    for (int i = 0; i < n; ++i) {
        if (m == 0) {
            iv[m++] = iv[i];
            continue;
        }
        Interval *prev = &iv[m-1];
        if (iv[i].start <= prev->end + 1) { // overlap or contiguous -> merge
            if (iv[i].end > prev->end) prev->end = iv[i].end;
        } else {
            iv[m++] = iv[i];
        }
    }

    Interval *res = realloc(iv, sizeof(Interval) * (size_t)m);
    if (!res && m > 0) { free(iv); perror("realloc"); exit(1); }
    *out_count = m;
    return res;
}

int in_intervals(const Interval *iv, int m, long x) {
    int lo = 0, hi = m - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (x < iv[mid].start) {
            hi = mid - 1;
        } else if (x > iv[mid].end) {
            lo = mid + 1;
        } else {
            return 1;
        }
    }
    return 0;
}

arrayptr buildRange(long first[], long second[], int size) {
    long arrayIndex = 0;
    long arrSize = 100000;
    long* arr = malloc(sizeof(long) * arrSize);
    for(int i = 0; i < size; i++){
        for(long ii = first[i]; ii <= second[i]; ii++) {
            //should have just been a map but dont want to make one
            if(arrayIndex >= arrSize) {
                qsort(arr, arrayIndex, sizeof(long), cmpfunc);
                long current = -1;
                long index = 0;
                for (long i = 0; i < arrayIndex; i++){
                    if (arr[i] != current){
                        arr[index++] = arr[i];
                    }
                    current = arr[i];
                }
                arrayIndex = index;
                arrSize = index+100000;
                arr = realloc(arr, sizeof(long) * arrSize);
            }
            arr[arrayIndex] = ii;
            arrayIndex++;
        }
    }
    qsort(arr, arrayIndex, sizeof(long), cmpfunc);
    long current = -1;
    long index = 0;
    for (long i = 0; i < arrayIndex; i++){
        if (arr[i] != current){
            arr[index++] = arr[i];
        }
        current = arr[i];
    }
    arrayptr ret = {index, arr};
    return ret;
}

long buildRangep2(long first[], long second[], int size) {
    long arrayIndex = 0;
    long arrSize = 100000;
    for(int i = 0; i < size; i++){
        for(long ii = first[i]; ii <= second[i]; ii++) {
            arrayIndex++;
        }
    }
    return arrayIndex;
}


int count(arrayptr range, long num) {
    long *p = bsearch(&num, range.arr, (size_t)range.size, sizeof(long), cmpfunc);
    return p != NULL;
}

unsigned long long count_covered(const Interval *iv, int m) {
    unsigned long long total = 0;
    for (int i = 0; i < m; ++i) {
        total += (unsigned long long)(iv[i].end - iv[i].start + 1);
    }
    return total;
}

int main() {
    char line[500];
    int flip = 1;
    int itr = 0;
    long first, second;
    long firstArr[200];
    long secondArr[200];
    long num;
    arrayptr range;
    int res = 0;
    int m;
    Interval *merged;
    while(fgets(line, sizeof(line), stdin) != NULL){
        if (is_blank_line(line) && !flip) {
            break;
        } else if (is_blank_line(line)) {
            merged = merge_intervals(firstArr, secondArr, itr, &m);
            unsigned long long total = count_covered(merged, m);
            printf("%llu\n", total);
            flip = 0;
            continue;
        }
        if(flip) {
            sscanf(line, "%ld-%ld", &first, &second);
            firstArr[itr] = first;
            secondArr[itr] = second;
            itr++;
        } else {
            sscanf(line, "%ld", &num);
            res += in_intervals(merged, m, num);
        }
    }
    printf("%d\n", res);
    free(merged);
    return 0;
}