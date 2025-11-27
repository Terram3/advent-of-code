#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int parse_digit(const char *str, int i) {
    if (isdigit(str[i])) return str[i] - '0';
    if (!strncmp(&str[i], "one", 3)) return 1;
    if (!strncmp(&str[i], "two", 3)) return 2;
    if (!strncmp(&str[i], "three", 5)) return 3;
    if (!strncmp(&str[i], "four", 4)) return 4;
    if (!strncmp(&str[i], "five", 4)) return 5;
    if (!strncmp(&str[i], "six", 3)) return 6;
    if (!strncmp(&str[i], "seven", 5)) return 7;
    if (!strncmp(&str[i], "eight", 5)) return 8;
    if (!strncmp(&str[i], "nine", 4)) return 9;
    return -1;
}

int logic(char* line){
    int res = 0;
    int firstVal = 0;
    int first = 1;
    int secondVal = 0;
    for(int i = 0; line[i] != '\0'; i++){
        if(parse_digit(line, i) != -1 && first == 1){
            firstVal = parse_digit(line, i) * 10;
            res = firstVal;
            printf("First val: %d\n", firstVal);
            first = 0;
        } else if(parse_digit(line, i) != -1){
            secondVal = parse_digit(line, i);
            res = firstVal + parse_digit(line, i);
        }
    }
    if(secondVal == 0){
        res = firstVal + firstVal/10;
    }
    printf("Line value: %d\n", res);
    return res;
}


int logic2(char* line){
    int res = 0;
    int firstVal = 0;
    int first = 1;
    int secondVal = 0;
    for(int i = 0; line[i] != '\0'; i++){
        if(isdigit(line[i]) && first == 1){
            firstVal = (line[i] - '0') * 10;
            res = firstVal;
            first = 0;
        } else if(isdigit(line[i])){
            secondVal = (line[i] - '0');
            res = firstVal + (line[i] - '0');
        }
    }
    if(secondVal == 0){
        res = firstVal + firstVal/10;
    }
    printf("Line value: %d\n", res);
    return res;
}

int main(){
    char line[100];
    int acc = 0;
    while(fgets(line, sizeof line, stdin)!=NULL && line[0]!='\n'){
        printf("Line: %s", line);
        acc += logic(line);
        printf("Acc: %d\n", acc);
    }
    printf("Res: %d\n", acc);
    return 0;
}