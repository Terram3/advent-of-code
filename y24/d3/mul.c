#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int enabled = 1;

long mulCompute(char *line) {
    size_t nlen = strlen(line);
    char *p = line;
    int a, b = 0;
    int pos;
    long count = 0;
    while ((p = strstr(p, "mul(")) != NULL) {
        if (sscanf(p, "mul(%d,%d)%n", &a, &b, &pos) == 2 && p[pos-1] == ')') {
            printf("Found: mul(%d,%d)\n", a, b);
            /* if(a > 0 && a < 1000 && b > 0 && b < 1000) {
            
            } */
            count += a * b; 
        }
        p++;
    }
    return count;
}

long mulComputeP2(char *line) {
    char *p = line;
    size_t nlen = strlen(line);
    int a, b = 0;
    int pos;
    long count = 0;
    while (*p) {
        if (strncmp(p, "don't()", 7) == 0) {
            enabled = 0;
            p+=7;
            continue;
        } else if(strncmp(p, "do()", 4) == 0) {
            enabled = 1;
            p+=4;
            continue;
        } else if(strncmp(p, "mul(", 4) == 0 && enabled) {
            if (sscanf(p, "mul(%d,%d)%n", &a, &b, &pos) == 2 && p[pos-1] == ')') {
                printf("Found: mul(%d,%d)\n", a, b);
                if(a > 0 && a < 1000 && b > 0 && b < 1000) {
                    count += a * b; 
                }
            }
            p++;
        }    
        p++;
    }
    return count;
}


int main() {
    char line[4096];
    long count = 0;
    while(fgets(line, sizeof line, stdin) != NULL) {
        line[strcspn(line, "\r\n")] = '\0';
        if (line[0] == '\0') continue;
        count += mulComputeP2(line);
    }
    printf("%ld\n", count);
    return 0;
}