#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UP 4
#define RIGHT 3
#define DOWN 2
#define LEFT 1

int guardRoute(char lines[140][140], int size){
    int cordX = 0;
    int cordY = 0;
    for (int i = 0; i < size; i++){
        for(int ii = 0; ii < size; ii++){
            if(lines[i][ii] == '^'){
                cordY = i;
                cordX = ii;
            }
        }
    }
    int direction = UP;
    bool visited[140][140] = {};
    while((cordX >= 0) && (cordX < 130) && (cordY >= 0) && (cordY < 130)){
        if(direction == UP){
            if(lines[cordY][cordX] == '#'){
                direction = RIGHT;
                cordY++;
            } else {
                visited[cordY][cordX] = true;
                cordY--;
            }
        }
        else if(direction == RIGHT){
            if(lines[cordY][cordX] == '#'){
                direction = DOWN;
                cordX--;
            } else {
                visited[cordY][cordX] = true;
                cordX++;
            }
        }
        if(direction == DOWN){
            if(lines[cordY][cordX] == '#'){
                direction = LEFT;
                cordY--;
            } else {
                visited[cordY][cordX] = true;
                cordY++;
            }
        }
        if(direction == LEFT){
            if(lines[cordY][cordX] == '#'){
                direction = UP;
                cordX++;
            } else {
                visited[cordY][cordX] = true;
                cordX--;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < size; i++){
        for(int ii = 0; ii < size; ii++){
            if(visited[i][ii]){
                result++;
            }
        }
    }
    return result;
}

int main(){
    char lines[140][140];
    int i = 0;
    while(fgets(lines[i], sizeof(lines[i]), stdin)){
        if(lines[i][0] == '\n'){
            break;
        }
        i++;
    }
    printf("Result: %d\n", guardRoute(lines, i));
    return 0;
}