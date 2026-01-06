#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatrix(const char paper[][1100], int itr){
    for(int i = 0; i < itr; i++){
        printf("%s\n", paper[i]);
    }
}

long indexCount(const char paper[][1100], int itr, int row, int col){
    int count = 0;
    for(int i = row-1; i <= row+1; i++){
        if(i < 0 || i >= itr){
            continue;
        }
        for (int ii = col-1; ii <= col+1; ii++){
            if(i == row && ii == col || (i < 0 || i >= itr)){
                continue;
            }
            if(paper[i][ii] == '@'){
                count++;
            } 
        }
    }
    if (count < 4) {
        return 1;
    }
    return 0;
}

long countPaper(const char paper[][1100], int itr){
    long res = 0;
    for(int i = 0; i < itr; i++){
        for (int ii = 0; ii < strlen(paper[i]); ii++){
            if(paper[i][ii] == '@'){
                res += indexCount(paper, itr, i, ii);
            }
        }
    }
    return res;
}

long countPaperp2(const char paper[][1100], int itr){
    int res = 0;
    int newRes = 1;
    while(res == 0 || newRes != 0){
        newRes = 0;
        char** newMat = malloc(itr * sizeof(char*));
        int length = strlen(paper[0]);
        for (int i = 0; i < itr; i++) newMat[i] = malloc((length + 1) * sizeof(char));
        for (int i = 0; i < itr; i++){
            strcpy(newMat[i], paper[i]);
        }
        for (int i = 0; i < itr; i++){
            for (int ii = 0; ii < strlen(paper[i]); ii++){
                if(paper[i][ii] == '@' && indexCount(paper, itr, i, ii) == 1){
                    newMat[i][ii] = '.';
                    newRes++;
                }
            }
        }
        res = res + newRes;
        for (int i = 0; i < itr; i++) {
            strcpy((char*)paper[i], newMat[i]);
            free(newMat[i]);
        }
        free(newMat);
    }
    return res;
}


int main() {
    char str[5000][1100];
    long result = 0;
    int itr = 0;
    while (fgets(str[itr], sizeof(str[itr]), stdin) != NULL){
        if(str[itr][0] == '\n'){
            break;
        }
        str[itr][strcspn(str[itr], "\n")] = 0;  // Remove newline character;
        itr++;
    }
    printMatrix(str, itr);
    result = countPaperp2(str, itr);
    printf("Total Length: %ld\n", result);
    return 0;
}