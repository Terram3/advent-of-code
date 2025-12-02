#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long idCounter(unsigned long first, unsigned long second) {
    unsigned long count = 0;
    char* str;
    char* strFirst;
    char* strSecond;
    str = malloc(20 * sizeof(char));
    strFirst = malloc(10 * sizeof(char));
    strSecond = malloc(10 * sizeof(char));
    printf("First: %lu, Second: %lu\n", first, second);
    for(unsigned long i = first; i <= second; i++) {
        sprintf(str, "%lu", i);
        if(strlen(str) % 2 != 0) {
            continue;
        }
        int nDigits = strlen(str)/2;
        strncpy(strFirst, str, nDigits);
        strFirst[nDigits] = '\0';
        strncpy(strSecond, str + nDigits, nDigits);
        strSecond[nDigits] = '\0';
        if(strncmp(strFirst, strSecond, nDigits) == 0) {
            count += i;
        }
    }
    free(str);
    free(strFirst);
    free(strSecond);
    printf("%lu\n", count);
    return count;
}

long idCounterP2(unsigned long first, unsigned long second) {
    unsigned long count = 0;
    char* str;
    char* strFirst;
    char* strSecond;
    str = malloc(20 * sizeof(char));
    strSecond = malloc(10 * sizeof(char));
    printf("First: %lu, Second: %lu\n", first, second);
    for(unsigned long i = first; i <= second; i++) {
        sprintf(str, "%lu", i);
        for(int j = 2; j <= 10; j++) {
            int nDigits = strlen(str)/j;
            strFirst = malloc(10 * sizeof(char));
            strncpy(strFirst, str, nDigits);
            strFirst[nDigits] = '\0';
            if(strlen(str) % j == 0) {
                int countMatch = 0;
                for(int k = 1; k < j; k++) {
                    strSecond = malloc(10 * sizeof(char));
                    strncpy(strSecond, str + k * nDigits, nDigits);
                    strSecond[nDigits] = '\0';
                    if(strncmp(strFirst, strSecond, nDigits) != 0) {    
                        countMatch = 1;
                    }
                }
                if(countMatch == 0) {
                    count += i;
                    break;
                }
            }
        }
    }
    free(str);
    free(strFirst);
    free(strSecond);
    printf("%lu\n", count);
    return count;
}


int main() {
    char buf[1024];
    unsigned long first, second;
    unsigned long result = 0;
    while (fgets(buf, sizeof buf, stdin)) {
        char *saveptr = NULL;
        char *tok = strtok_r(buf, ",\n", &saveptr);
        while (tok) {
            if (sscanf(tok, "%lu-%lu", &first, &second) == 2) {
                result += idCounterP2(first, second);
            }
            tok = strtok_r(NULL, ",\n", &saveptr);
        }
    }
    printf("%lu\n", result);
    return 0;
}