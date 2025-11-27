#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    char line[100];
    int count = 0;
    char* chr;
    while(fgets(line, sizeof line, stdin)!=NULL && line[0]!='\n'){
        int data;
        int oldData = -1;
        int save = 1;
        int direction = -1;

        chr = strtok(line, " ");
        while(chr != NULL){
            sscanf(chr, "%d", &data);
            printf("data: %d\n", data);
            if(oldData == -1){
                oldData = data;
            } else if(direction == -1 && oldData + 4 > data && data > oldData) {
                direction = 1;
                oldData = data;
            } else if(direction == -1 && oldData - 4 < data && data < oldData) {
                direction = 0;
                oldData = data;
            } else if((oldData + 4 > data && data > oldData && direction == 1) || (oldData - 4 < data && data < oldData && direction == 0)){
                oldData = data;
            } else {
                save = 0;
                break;
            }
            chr = strtok(NULL, " \n");
        }
        if(save == 1){
            count++;
        }
    }
    printf("Total: %d\n", count);
    return 0;
}