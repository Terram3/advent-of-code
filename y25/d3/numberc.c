#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long countLine(const char* line) {
    long res = 0;
    long max = 0;
    int fromIndex = 0;
    for(int i = 0; i < strlen(line) - 1; i++) {
        if(max < (line[i]) - '0') {
            max = (line[i]) - '0';
            fromIndex = i + 1;
        }
    }
    res = max*10;
    max = 0;
    for(int i = fromIndex; i < strlen(line); i++) {
        if(max < (line[i]) - '0') {
            max = (line[i]) - '0';
        }
    }
    printf("Line: %s, Res: %ld + %ld = %ld\n", line, res, max, res+max);
    return res+max;
}

long countLinep2(const char* line) {
    long res = 0;
    long max = 0;
    int fromIndex = 0;
    int fromEnd = 11;
    for(int i = 0; i < 12; ++i) {
        for(int ii = fromIndex; ii < strlen(line)-fromEnd; ++ii) {
            if(max < (line[ii]) - '0') {
                max = (line[ii]) - '0';
                fromIndex = ii + 1;
            }
        }
        if(res == 0){
            res = max;
        } else {
            res = res*10 + max;
        }
        max = 0;
        fromEnd--;
    }
    printf("Line: %s, Res: %ld + %ld = %ld\n", line, res, max, res+max);
    return res+max;
}

int main() {
    char str[110];
    long result = 0;
    while (fgets(str, sizeof(str), stdin) != NULL){
        str[strcspn(str, "\n")] = 0;  // Remove newline character
        result += countLinep2(str);
    }
    printf("Result: %ld\n", result);
    return 0;
}