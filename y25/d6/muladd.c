#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct MulAdd {
    long *firstNum;
    long *secondNum;
    long *thirdNum;
    long *fourthNum;
    char *operation;
} MulAdd;

unsigned long long sumMulAdd(MulAdd *ma, int index);

int parseLine(char *line, long *numbers){
    char *copy = strdup(line);
    char *token = strtok(copy, " \n\t");
    int count = 0;
    while(token != NULL){
        numbers[count] = strtol(token, NULL, 10);
        count++;
        token = strtok(NULL, " \n\t");
    }
    free(copy);
    printf("Parsed %d numbers from line.\n", count);
    return count;  // Return how many were parsed
}

int main2(){
    char line[4096];
    MulAdd ma;
    ma.firstNum = malloc(1005 * sizeof(long));
    ma.secondNum = malloc(1005 * sizeof(long));
    ma.thirdNum = malloc(1005 * sizeof(long));
    ma.fourthNum = malloc(1005 * sizeof(long));
    ma.operation = malloc(1005 * sizeof(char));
    int check;
    for(int i = 0; i < 5; i++){
        fgets(line, sizeof(line), stdin);
        if(i == 0){
            check = parseLine(line, ma.firstNum);
        } else if(i == 1){
            check = parseLine(line, ma.secondNum);
        } else if(i == 2){
            check = parseLine(line, ma.thirdNum);
        } else if (i == 3){
            check = parseLine(line, ma.fourthNum);
        } else if(i == 4){
            char *copy = strdup(line);
            char *token = strtok(copy, " \n\t");
            int count = 0;
            while(token != NULL){
                ma.operation[count] = token[0];
                count++;
                token = strtok(NULL, " \n\t");
            }
            ma.operation[count] = '\0'; // Null-terminate the string
            free(copy);
        }
    }
    unsigned long long res = sumMulAdd(&ma, check);
    printf("Result: %llu\n", res);
    free(ma.firstNum);
    free(ma.secondNum);
    free(ma.thirdNum);
    free(ma.fourthNum);
    free(ma.operation); 
    return 0;
}

int skipUntilRow(char topLine[5][4096], int start){
    for(int i = start; i < start + 4096; i++){
        int allSpaces = 1;
        for(int ii = 0; ii < 5; ii++){
            if(topLine[ii][i] != ' '){
                allSpaces = 0;
                break;
            }
        }
        if(allSpaces){
            return i - start;
        }
    }
    return -1; 
}

unsigned long long parseMatp2(char line[5][4096]){
    int i = 0;
    unsigned long long res = 0;
    while(i < strlen(line[0])){
        int skipLoop = skipUntilRow(line, i);
        if(skipLoop == -1 || skipLoop > 4){
            skipLoop = strlen(line[0])-i-1;
            if(skipLoop==0){
                break;
            }
        }
        int add = 0;
        if(line[4][i] == '+'){
            add = 1;
        } 
        unsigned long long sum = 0;
        for(int ii = i; ii < i+skipLoop; ii++){
            unsigned long long num = 0;
            for(int iii = 0; iii < 4; iii++){
                if(line[iii][ii]  != ' '){
                    num = num*10+(line[iii][ii] - '0');
                }
            }
            if(add){
                sum += num;
            } else {
                sum = sum == 0 ? num : sum*num;
            }
            printf("Current number: %llu, Current sum: %llu\n", num, sum);
        }
        res += sum;
        i += skipLoop+1;
    }
    return res;
}

unsigned long long sumMulAdd(MulAdd *ma, int index){
    unsigned long long result = 0;
    unsigned long long tempResult = 0;
    for(int i = 0; i < index; i++){
        if (ma->operation[i] == '*'){
            if (ma->firstNum[i] == 0){
                ma->firstNum[i] = 1;
            } else if( ma->secondNum[i] == 0){
                ma->secondNum[i] = 1;
            } else if( ma->thirdNum[i] == 0){
                ma->thirdNum[i] = 1;
            } else if( ma->fourthNum[i] == 0){
                ma->fourthNum[i] = 1;
            }
            printf("Multiplying %ld, %ld, %ld, %ld\n", ma->firstNum[i], ma->secondNum[i], ma->thirdNum[i], ma->fourthNum[i]);
            tempResult = ma->firstNum[i] * ma->secondNum[i] * ma->thirdNum[i] * ma->fourthNum[i];
        } else if(ma->operation[i] == '+'){
            printf("Adding %ld, %ld, %ld, %ld\n", ma->firstNum[i], ma->secondNum[i], ma->thirdNum[i], ma->fourthNum[i]);
            tempResult = ma->firstNum[i] + ma->secondNum[i] + ma->thirdNum[i] + ma->fourthNum[i];
        }
        printf("Operation %c on index %d gives %llu\n", ma->operation[i], i, tempResult);
        result += tempResult;
    }
    return result;
}

int main(){
    char line[5][4096];
    for(int i = 0; i < 5; i++){
        fgets(line[i], sizeof(line[i]), stdin);
    }
    unsigned long long res = parseMatp2(line);
    printf("Result: %llu\n", res);
    return 0;
}