#include <stdio.h>
#include <stdlib.h>

int get_dial_position(char direction, int current, int amount, int* counter){
    if (amount > 100) amount = amount%100;
    if(direction == 'L'){
        current -= amount;
        if(current < 0) current += 100;
    } else if(direction == 'R'){
        current += amount;
        if(current >= 100) current -= 100;
    }
    if(current == 0){
        (*counter)++;
    }
    return current;
}

int get_dial_positionp2(char direction, int current, int amount, int* counter){
    if (amount >= 100) {
        *counter += (int)(amount / 100);
        amount = (int)(amount % 100);
    }
    if(direction == 'L'){
        if (current != 0){
            current -= amount;
            if(current == 0) (*counter)++;
            if(current < 0) {
                current += 100;
                (*counter)++;
            }
        } else {
            current -= amount;
            if(current == 0) (*counter)++;
            if(current < 0) {
                current += 100;
            }
        }   
    } else if(direction == 'R'){
        current += amount;
        if(current >= 100) {
            current -= 100;
            (*counter)++;
        }
    }
    return current;
}

int main(){
    char line[100];
    int count = 0;
    int dial = 50;
    char chr;
    int data;
    while(fgets(line, sizeof line, stdin) != NULL && line[0] != '\n'){
        sscanf(line, " %c%d", &chr, &data);
        dial = get_dial_positionp2(chr, dial, data, &count);
    }
    printf("%d\n", count);
    return 0;
}
