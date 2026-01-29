#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct cords {
    int x;
    int y;
    int z;
} cords;

typedef struct min_distance {
    int min_index1;
    int min_index2;
    double min;
} min_distance;

typedef struct connected_groups {
    int indexes[1000];
    int value;
} connected_groups;

unsigned long pow2(int base){
    int result = 1;
    for(int i = 0; i < 2; i++){
        result *= base;
    }
    return result;
}

int cmp(const void *a, const void *b){
    min_distance *min_dist1 = (min_distance *)a;
    min_distance *min_dist2 = (min_distance *)b;
    return (min_dist1->min - min_dist2->min);
}

int cmp2(const void *a, const void *b){
    connected_groups *min_dist1 = (connected_groups *)a;
    connected_groups *min_dist2 = (connected_groups *)b;
    return (min_dist2->value - min_dist1->value);
}

int mergeIds(connected_groups *circuits, int length, min_distance temp, int* circuitId){
    int id1 = circuitId[temp.min_index1];
    int id2 = circuitId[temp.min_index2];

    connected_groups *circ1 = &circuits[id1];
    connected_groups *circ2 = &circuits[id2];
    for(int i = 0; i < 1000; i++){
        int idx = circ2->indexes[i];
        if (idx == -1) continue;
        int skip = circ1->value;
        circ1->indexes[skip] = idx;
        circuitId[idx] = id1;
        circ1->value++;
    }
    memset(circ2->indexes, -1, sizeof(circ2->indexes));
    circ2->value = 0;
    return 0;
}

int indexCheck(connected_groups* circuits_cur, int length, min_distance temp, int* circuitId){
    int id1 = circuitId[temp.min_index1];
    int id2 = circuitId[temp.min_index2];
    if(id1 == -1 && id2 == -1){
        int newIdx = -1;
        for (int i = 0; i < length; i++) {
            if (circuits_cur[i].value == 0) {
                newIdx = i;
                break;
            }
        }
        connected_groups *circuits = &circuits_cur[newIdx];
        circuits->indexes[0] = temp.min_index1;
        circuits->indexes[1] = temp.min_index2;
        circuitId[temp.min_index1] = newIdx;
        circuitId[temp.min_index2] = newIdx;
        circuits->value = 2;
    } else if(id1 != -1 && id2 == -1) {
        connected_groups *circuits = &circuits_cur[id1];
        int pos = 0;
        while (pos < 1000 && circuits->indexes[pos] != -1){
            pos++;
        }
        int newPoint = temp.min_index2;
        circuits->indexes[pos] = newPoint;
        circuits->value++;
        circuitId[newPoint] = id1;
    } else if(id1 == -1 && id2 != -1){
        connected_groups *circuits = &circuits_cur[id2];
        int pos = 0;
        while (pos < 1000 && circuits->indexes[pos] != -1){
            pos++;
        }
        int newPoint = temp.min_index1;
        circuits->indexes[pos] = newPoint;
        circuits->value++;
        circuitId[newPoint] = id2;
    } else if(id1 != -1 && id2 != -1 && id1 != id2) {
        mergeIds(circuits_cur, length, temp, circuitId);
    }
    return 0;
}

long playgroundprob(cords cordinates[1024], int length){
    long total_pairs = (long)length * (length - 1) / 2;
    min_distance *min_distances = malloc(sizeof(min_distance) * total_pairs);
    int itr = 0;
    for (int i = 0; i < length; i++) {
        for (int ii = i + 1; ii < length; ii++) {
            double distance = sqrt(
                pow2(cordinates[i].x - cordinates[ii].x) +
                pow2(cordinates[i].y - cordinates[ii].y) +
                pow2(cordinates[i].z - cordinates[ii].z)
            );
            min_distances[itr].min = distance;
            min_distances[itr].min_index1 = i;
            min_distances[itr].min_index2 = ii;
            itr++;
        }
    }
    qsort(min_distances, itr, sizeof(min_distance), cmp);
    connected_groups *circuits = malloc(1000*sizeof(connected_groups));
    for(int i = 0; i < 1000; i++){
        connected_groups cir;
        memset(cir.indexes, -1, sizeof(int) * 1000);
        cir.value = 0;
        circuits[i] = cir;
    }
    int *circuitsId = malloc(sizeof(int)*1000);
    memset(circuitsId, -1, sizeof(int) * 1000);
    for (int i = 0; i < 1000; i++) {
        indexCheck(circuits, 1000, min_distances[i], circuitsId);
    }
    qsort(circuits, 1000, sizeof(connected_groups), cmp2);
    int sum = 1;
    for(int i = 0; i < 3; i++){
        printf("Data for group: %d\n", circuits[i].value);
        sum *= circuits[i].value;
    }
    return sum;
}

int main(){
    char line[1024];
    int i = 0;
    cords cordinates[1024];
    while(fgets(line, sizeof(line), stdin)){
        if(line[0] == '\n'){
            break;
        }
        cords cordinate;
        sscanf(line, "%d,%d,%d", &cordinate.x, &cordinate.y, &cordinate.z);
        cordinates[i] = cordinate;
        i++;
    }
    printf("Sum of connections: %ld\n",  playgroundprob(cordinates, i));
    return 0;
}