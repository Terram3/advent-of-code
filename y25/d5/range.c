#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contains(long* arr, int size, int num){
    for (int i = 0; i < size; i++){
        if (num == arr[i]){
            return 1;
        }
    }
    return 0;
    
}

long* buildRange(long first[], long second[], int size) {
    int arrayIndex = 0;
    long* arr = malloc(sizeof(int) * 10000);
    for(int i = 0; i < size; i++){
        for(int ii = first[i]; ii <= second; ii++) {
            if(!contains(arr, arrayIndex, ii)){
                arr[arrayIndex] = ii;
                arrayIndex++;
            }   
        }
    }
    return arr;
}

int main() {
    char line[500];
    int flip = 1;
    int itr = 0;
    long first, second;
    long firstArr[10000];
    long secondArr[10000];
    while(fgets(line, sizeof(line), stdin) != NULL){
        if (line[0] == '\n') {
            buildRange(firstArr, secondArr, itr);
            flip = 0;
        } else if(line[1] == '\n') {
            break;
        }
        if(flip) {
            sscanf(line, "%ld-%ld", &first, &second);
            firstArr[itr] = first;
            secondArr[itr] = second;
        } else {

        }
        itr++;

    }
    return 0;
}