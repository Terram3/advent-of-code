#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int valid_without_removal(int *arr, int m){
    if(m <= 1) return 1;
    int dir = -1;
    for(int i = 1; i < m; ++i){
        int prev = arr[i-1];
        int cur = arr[i];
        if(cur == prev) return 0;
        if(dir == -1){
            if(cur > prev){
                if(!(cur > prev && cur < prev + 4)) return 0;
                dir = 1;
            } else { /* cur < prev */
                if(!(cur < prev && cur > prev - 4)) return 0;
                dir = 0;
            }
        } else if(dir == 1){
            if(!(cur > prev && cur < prev + 4)) return 0;
        } else { /* dir == 0 */
            if(!(cur < prev && cur > prev - 4)) return 0;
        }
    }
    return 1;
}

int main(){
    char line[100];
    int count = 0;
    char* chr;
    while(fgets(line, sizeof line, stdin) != NULL && line[0] != '\n'){
        int nums[100];
        int n = 0;

        chr = strtok(line, " \n");
        while(chr != NULL){
            if(sscanf(chr, "%d", &nums[n]) == 1){
                n++;
            }
            chr = strtok(NULL, " \n");
        }
        if(n == 0) continue;
        if(valid_without_removal(nums, n)){
            count++;
            continue;
        }

        int became_valid = 0;
        for(int skip = 0; skip < n && !became_valid; skip++){
            int tmp[50];
            int t = 0;
            for(int i = 0; i < n; ++i){
                if(i == skip) continue;
                tmp[t++] = nums[i];
            }
            if(valid_without_removal(tmp, t)){
                became_valid = 1;
            }
        }
        if(became_valid) count++;
    }
    printf("Total: %d\n", count);
    return 0;
}