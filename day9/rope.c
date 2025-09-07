#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZEX 10
#define ARRAY_SIZEY 10

int mat[ARRAY_SIZEX][ARRAY_SIZEY];
int values[10][2];
int size = 1;
char lastDir;
int lastPositionX = -1;
int lastPositionY = ARRAY_SIZEY;
int lastPositionHX = 0;
int lastPositionHY = ARRAY_SIZEY - 1;


void moveLogic(char dir){
    if(dir == 'R'){
        lastPositionHX++;
        if (lastPositionHX > lastPositionX + 1) {
            lastPositionX++;
            if (lastPositionHY > lastPositionY) {
                lastPositionY++;
            } else if (lastPositionHY < lastPositionY) {
                lastPositionY--;
            }
        }
    }
    if(dir == 'L'){
        lastPositionHX--;
        if (lastPositionHX < lastPositionX - 1) {
            lastPositionX--;
            if (lastPositionHY > lastPositionY) {
                lastPositionY++;
            } else if (lastPositionHY < lastPositionY) {
                lastPositionY--;
            }
        }
    }
    if(dir == 'D'){
        lastPositionHY++;
        if (lastPositionHY > lastPositionY + 1) {
            lastPositionY++;
            if (lastPositionHX > lastPositionX) {
                lastPositionX++;
            } else if (lastPositionHX < lastPositionX) {
                lastPositionX--;
            }
        }
    }
    if(dir == 'U'){
        lastPositionHY--;
        if (lastPositionHY < lastPositionY - 1) {
            lastPositionY--;
            if (lastPositionHX > lastPositionX) {
                lastPositionX++;
            } else if (lastPositionHX < lastPositionX) {
                lastPositionX--;
            }
        }
    }
    if(lastPositionX < 0 || lastPositionX >= ARRAY_SIZEX || lastPositionY < 0 || lastPositionY >= ARRAY_SIZEY){
        printf("Out of bounds! X: %d, Y: %d\n", lastPositionX, lastPositionY);
    } else {
        mat[lastPositionX][lastPositionY] = 1;
    }
}

void moveLogicTest(char dir, int prevX, int prevY){
    if(dir == 'R'){
        prevX++;
        if (prevX > lastPositionX + 1) {
            lastPositionX++;
            if (prevY > lastPositionY) {
                lastPositionY++;
            } else if (prevY < lastPositionY) {
                lastPositionY--;
            }
        }
    }
    if(dir == 'L'){
        prevX--;
        if (prevX < lastPositionX - 1) {
            lastPositionX--;
            if (prevY > lastPositionY) {
                lastPositionY++;
            } else if (prevY < lastPositionY) {
                lastPositionY--;
            }
        }
    }
    if(dir == 'D'){
        prevY++;
        if (prevY > lastPositionY + 1) {
            lastPositionY++;
            if (prevX > lastPositionX) {
                lastPositionX++;
            } else if (prevX < lastPositionX) {
                lastPositionX--;
            }
        }
    }
    if(dir == 'U'){
        prevY--;
        if (prevY < lastPositionY - 1) {
            lastPositionY--;
            if (prevX > lastPositionX) {
                lastPositionX++;
            } else if (prevX < lastPositionX) {
                lastPositionX--;
            }
        }
    }
    if(lastPositionX < 0 || lastPositionX >= ARRAY_SIZEX || lastPositionY < 0 || lastPositionY >= ARRAY_SIZEY){
        printf("Out of bounds! X: %d, Y: %d\n", lastPositionX, lastPositionY);
    } else {
        mat[lastPositionX][lastPositionY] = 1;
    }
}

void moveLogicP2(char dir){
    for(int i = 1; i < size; i++){
        
    }
}

void logic(char dir, int steps){
    for(int i = 1; i <= steps; i++){
        //moveLogic(dir);
        moveLogicP2(dir);
    }
}

void printMat(){
    int res = 0;
    for(int i = 0; i < ARRAY_SIZEY; i++){
        for(int ii = 0; ii < ARRAY_SIZEX; ii++){
            printf("%d ", mat[ii][i]);
            res += mat[i][ii];
        }
        printf("\n");
    }
    printf("Res: %d\n", res);
}

int main(){
    char* line;
    line = malloc(sizeof(char)*8);
    while(fgets(line, sizeof line, stdin)!=NULL && line[0]!='\n'){
        int steps;
        char direction;
        sscanf(line, "%c %d", &direction, &steps);
        logic(direction, steps);
    }
    printMat();
    free(line);
    return 0;
}