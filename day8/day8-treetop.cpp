#include <iostream>
#include <string>

struct {
    int leftEdge;
    int topEdge;
    int rightEdge;
    int bottomEdge;
} edges;

int saveLine(std::string read, int** matrix, int i, int size){
    std::cout << read << "\n";
    matrix[i] = (int*) malloc(size * sizeof(int));
    for(int j = 0; j < size; j++){
        matrix[i][j] = read[j] - '0';
    }
    return 1;
}

int printMat(int** matrix, int iTop, int jTop){
    for(int i = 0; i < iTop; i++){
        for(int j = 0; j < jTop; j++){
            printf("%d   ", matrix[i][j]);
        }
        printf("\n");
    }
    return 1;
}

bool visableFromOutsideMatrix(int** matrix, int col, int row, int size){
    int max = matrix[col][row];
    bool visible = true;
    for(int j = 0; j < row; j++){
        if(max <= matrix[col][j]){
            visible = false;
            std::cout << "i: " << col << "j: " << row << "\n";
            break;
        }
    }
    if(visible) return true;
    visible = true;
    for(int j = row+1; j < size; j++){
        if(max <= matrix[col][j]){
            visible = false;
            std::cout << "i: " << col << "j: " << row << "\n";
            break;
        }
    }
    if(visible) return true;
    visible = true;
    for(int i = 0; i < col; i++){
        if(max <= matrix[i][row]){
            visible = false;
            std::cout << "i: " << col << "j: " << row << "\n";
            break;
        }
    }
    if(visible) return true;
    visible = true;
    for(int i = col+1; i < size; i++){
        if(max <= matrix[i][row]){
            visible = false;
            std::cout << "i: " << col << "j: " << row << "\n";
            break;
        }
    }
    if(visible) return true;
    return false;
}

int scenicScoreOutsideMatrix(int** matrix, int col, int row, int size){
    int max = matrix[col][row];
    int scenicScore = 1;
    int score = 0;
    for(int j = row-1; j > -1; j--){
        score++;
        if(max <= matrix[col][j]){
            break;
        }
    }
    printf("Score: %d   ", score);
    scenicScore *= score;
    score = 0;
    for(int j = row+1; j < size; j++){
        score++;
        if(max <= matrix[col][j]){
            break;
        }
    }
    printf("Score: %d   ", score);
    scenicScore *= score;
    score = 0;
    for(int i = col-1; i > -1; i--){
        score++;
        if(max <= matrix[i][row]){
            break;
        }
    }
    printf("Score: %d   ", score);
    scenicScore *= score;
    score = 0;
    for(int i = col+1; i < size; i++){
        score++;
        if(max <= matrix[i][row]){
            break;
        }
    }
    printf("Score: %d", score);
    scenicScore *= score;
    printf("\n");
    return scenicScore;
}


int solve(int** matrix, int size){
    edges.leftEdge = 0;
    edges.topEdge = 0;
    edges.rightEdge = size-1;
    edges.bottomEdge = size-1;
    int result = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(edges.leftEdge == i || edges.bottomEdge == j || edges.rightEdge == i || edges.topEdge == j){
                result++;
            } else if(visableFromOutsideMatrix(matrix, i, j, size)){
                result++;
            }
        }
    }
    std::cout << result << "\n";
    return result;
}

int solve2(int** matrix, int size){
    edges.leftEdge = 0;
    edges.topEdge = 0;
    edges.rightEdge = size-1;
    edges.bottomEdge = size-1;
    int result = 0;
    int currentVal = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(edges.leftEdge == i || edges.bottomEdge == j || edges.rightEdge == i || edges.topEdge == j){
                continue;
            } else {
                currentVal = scenicScoreOutsideMatrix(matrix, i, j, size);
                if(currentVal > result){
                    result = currentVal;
                }
            }
        }
    }
    std::cout << result << "\n";
    return result;
}

int main(){
    std::string read;
    int** matrix;
    int i = 0;
    getline(std::cin, read);
    int size = read.size()-1;
    matrix = (int**) malloc(size * sizeof(int*));
    saveLine(read, matrix, i, size);
    std::cout << size << "\n";
    while(getline(std::cin, read)){
        i++;
        saveLine(read, matrix, i, size);
    }
    printMat(matrix, size, size);
    solve2(matrix, size);
}
