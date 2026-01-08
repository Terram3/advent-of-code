#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int count(arrayptr range, long num) {
    long *p = bsearch(&num, range.arr, (size_t)range.size, sizeof(long), cmpfunc);
    return p != NULL;
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
    while(fgets(line, sizeof(line), stdin) != NULL){
        if (is_blank_line(line) && !flip) {
            break;
        } else if (is_blank_line(line)) {
            range = buildRange(firstArr, secondArr, itr);
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
            res += count(range, num);
        }
    }
    printf("%d\n", res);
    free(range.arr);
    return 0;
}