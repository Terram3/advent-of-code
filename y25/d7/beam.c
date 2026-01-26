#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int beamCutting(char line[4096][1024], int len){
    int pointRow[1024];
    int res = 0;
    printf("%d, line: %lu", len, strlen(line[0]));
    for(int i = 0; i < len; i++){
        for (int ii = 0; ii < strlen(line[0]); ii++){
            if(line[i][ii]=='S'){
                pointRow[ii] = 1;
            } else if(line[i][ii]=='^' && pointRow[ii]){
                res++;
                pointRow[ii] = 0;
                pointRow[ii-1] = 1;
                pointRow[ii+1] = 1;
            } 
        }
    }
    return res;
}


unsigned long beamCuttingp2(char line[4096][1024], int len){
    unsigned long pointRow[1024];
    memset(pointRow, 0, sizeof(pointRow));
    for (int i = 0; i < strlen(line[0]); i++){
        if(line[0][i]=='S'){
            pointRow[i] = 1;
        } 
    }

    for(int i = 0; i < len; i++){
        for(int ii = 0; ii < strlen(line[0]); ii++){
            if(pointRow[ii] && line[i][ii]=='^'){
                pointRow[ii-1] += pointRow[ii];
                pointRow[ii+1] += pointRow[ii];
                pointRow[ii] = 0;
            }
        }
    }
    unsigned long res = 0;
    for(int i = 0; i < strlen(line[0]); i++){
        res += pointRow[i];
    }
    return res;
}


int main(){
    char line[4096][1024];
    int i = 0;
    while (fgets(line[i], sizeof(line[i]), stdin) != NULL){
        line[i][strcspn(line[i], "\n")] = 0;
        if(line[i][0] == '\n'){
            break;
        }
        i++;
    }
    printf("Result is: %lu\n", beamCuttingp2(line, i));
    return 0;
}