#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countXmasp1(char line[150][2048], int x, int y, int xw, int yh){
    int res = 0;
    if(x-3 >= 0 && line[x-1][y] == 'M' && line[x-2][y] == 'A' && line[x-3][y] == 'S'){
        res++;
    }
    if(x+3 < xw && line[x+1][y] == 'M' && line[x+2][y] == 'A' && line[x+3][y] == 'S'){
        res++;
    }
    if(y-3 >= 0 && line[x][y-1] == 'M' && line[x][y-2] == 'A' && line[x][y-3] == 'S'){
        res++;
    }
    if(y+3 < yh && line[x][y+1] == 'M' && line[x][y+2] == 'A' && line[x][y+3] == 'S'){
        res++;
    }
    if(x-3 >= 0 && y-3 >= 0 && line[x-1][y-1] == 'M' && line[x-2][y-2] == 'A' && line[x-3][y-3] == 'S'){
        res++;
    }
    if(x+3 < xw && y-3 >= 0 && line[x+1][y-1] == 'M' && line[x+2][y-2] == 'A' && line[x+3][y-3] == 'S'){
        res++;
    }
    if(x-3 >= 0 && y+3 < yh && line[x-1][y+1] == 'M' && line[x-2][y+2] == 'A' && line[x-3][y+3] == 'S'){
        res++;
    }
    if(x+3 < xw && y+3 < yh && line[x+1][y+1] == 'M' && line[x+2][y+2] == 'A' && line[x+3][y+3] == 'S'){
        res++;
    }
    return res;
}

int countMasp2(char line[150][2048], int x, int y, int xw, int yh){
    int res = 0;
    if(x-1 >= 0 && x+1 < xw && y-1 >= 0 && y+1 < yh
        && line[x-1][y-1] == 'M' && line[x+1][y+1] == 'S'
        && line[x+1][y-1] == 'M' && line[x-1][y+1] == 'S'){
        res++;
    } else if(x-1 >= 0 && x+1 < xw && y-1 >= 0 && y+1 < yh
        && line[x-1][y-1] == 'S' && line[x+1][y+1] == 'M'
        && line[x+1][y-1] == 'M' && line[x-1][y+1] == 'S'){
        res++;
    } else if(x-1 >= 0 && x+1 < xw && y-1 >= 0 && y+1 < yh
        && line[x-1][y-1] == 'M' && line[x+1][y+1] == 'S'
        && line[x+1][y-1] == 'S' && line[x-1][y+1] == 'M'){
        res++;
    } else if(x-1 >= 0 && x+1 < xw && y-1 >= 0 && y+1 < yh
        && line[x-1][y-1] == 'S' && line[x+1][y+1] == 'M'
        && line[x+1][y-1] == 'S' && line[x-1][y+1] == 'M'){
        res++;
    }
    return res;
}

int xmasMat(char line[150][2048], int length){
    int count = 0;
    int count2 = 0;
    int size = strlen(line[0]);
    for(int i = 0; i < length; i++){
        for(int ii = 0; ii < size; ii++){
            if(line[i][ii] == 'X'){
                count += countXmasp1(line, i, ii, size, length);
            }
            if(line[i][ii] == 'A'){
                count2 += countMasp2(line, i, ii, size, length);
            }
        }
    }
    printf("P1 result: %d, P2 result: %d\n", count, count2);
    return count;
}

int main(){
    char line[150][2048];
    int i = 0;
    while(fgets(line[i], sizeof(line), stdin) != NULL){
        if(line[i][0] == '\n'){
            break;
        }
        line[i][strcspn(line[i], "\n")] = '\0';
        i++;
    }
    printf("Result: %d\n", xmasMat(line, i));
    return 0;
}