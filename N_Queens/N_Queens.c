#include <stdio.h>
#include <stdbool.h>

#define Queens 4

void printBoard(int board[Queens][Queens]);
bool isSafe(int board[Queens][Queens], int row, int col);

bool solveBoard(int board[Queens][Queens], int col){
    if(col >= Queens){
        return true;
    }
    for(int a = 0; a < Queens; a++){
        if(isSafe(board, a, col)){
            board[a][col] = 1;
            if(solveBoard(board, col+1)){
                return true;
            }
            board[a][col] = 0;
        }
    }
    return false;
}

int main(){
    int board[Queens][Queens];
    for(int a = 0; a < Queens; a++){
        for(int b = 0; b < Queens; b++){
            board[a][b] = 0;
        }
    }
    if(solveBoard(board, 0) == false){
        printf("No Solution\n");
        return 0;
    }
    printBoard(board);
    return 0;
}

bool isSafe(int board[Queens][Queens], int row, int col){
    int a;
    int b;
    for(a = 0; a < Queens; a++){
        if(board[row][a]){
            return false;
        }
    }
    for(a = row, b = col; a >= 0 && b >= 0; a--, b--){
        if(board[a][b]){
            return false;
        }
    }
    for(a = row, b = col; a < Queens && b >= 0; a++, b--){
        if(board[a][b]){
            return false;
        }
    }
    return true;
}

void printBoard(int arr[Queens][Queens]){
    for(int a = 0; a < Queens; a++){
        for(int b = 0; b < Queens; b++){
            printf("%d ", arr[a][b]);
        }
        printf("\n");
    }
    printf("\n");
}
