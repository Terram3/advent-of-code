#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int xmasMat(char line[150][2048], int length){
    
    return 0;
}

int main(){
    char line[150][2048];
    int i = 0;
    while(fgets(line[i], sizeof(line), stdin) != NULL){
        if(line[i][0] == '\n'){
            break;
        }
        printf("%s", line[i]);
        i++;
    }
    return 0;
}