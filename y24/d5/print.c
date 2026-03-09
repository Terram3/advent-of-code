#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printPair(bool pairs[100][100]){
    for(int i = 0; i < 100; i++){
        for(int ii = 0; ii < 100; ii++){
            printf("%s", pairs[i][ii] ? "true   " : "false  ");
        }
        printf("\n");
    }
}

int solver(bool pairs[100][100], int numbers[200][30], int until){
    bool ok = false;
    bool savedRow = false;
    int rowLength;
    int result = 0;
    for (int i = 0; i < until; i++){
        rowLength = 0;
        ok = false;
        savedRow = false;
        for (int ii = 0; ii < 30; ii++){
            if(numbers[i][ii] == 0 && !savedRow){
                savedRow = true;
                rowLength=ii/2;
            }
            for(int iii = ii+1; iii < 30; iii++){
                if (pairs[numbers[i][ii]][numbers[i][iii]]) {
                    ok = true;
                    break;
                }
            }
        }
        if(!ok){
            printf("Row: %d, Col: %d, number: %d\n", i, rowLength,numbers[i][rowLength+1]);
            result+=numbers[i][rowLength];
        }
    }
    return result;
}


int main(){
    char line[1400][340];
    int i = 0;
    int flip = 0;
    bool pairs[100][100] = {};
    int numbers[200][30] = {0};

    char* chr;
    int n;
    int row = 0;
    while(fgets(line[i], sizeof(line[0]), stdin) != NULL){
        if(flip && line[i][0] == '\n'){
            break;
        } else if(line[i][0] == '\n'){
            flip = 1;
        }
        if(!flip){
            int p, p2;
            sscanf(line[i], "%d|%d", &p, &p2);
            pairs[p2][p] = true;
        } else {
            n = 0;
            char *saveptr = NULL;
            char *tok = strtok_r(line[i], ",\n", &saveptr);
            while (tok) {
                if (sscanf(tok, "%d", &numbers[row][n]) == 1) {
                    n++;
                }
                tok = strtok_r(NULL, ",\n", &saveptr);
            }
            if(n!=0){
                row++;
            }
        }
    }
    printf("Result: %d\n", solver(pairs, numbers, row));
    return 0;
}