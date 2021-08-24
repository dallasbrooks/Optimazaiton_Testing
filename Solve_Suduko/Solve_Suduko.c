#include <stdio.h>
#include <stdbool.h>

#define N 9

void printBoard(int board[N][N]);
bool isSafe(int board[N][N], int row, int col, int num);

bool solveSuduko(int board[N][N], int row, int col){
	if(row == N-1 && col == N){
		return true;
	}
	if(col == N){
		row++;
		col = 0;
	}
	if(board[row][col] > 0){
		return solveSuduko(board, row, col+1);
	}
	for(int a = 0; a < N; a++){
		if(isSafe(board, row, col, a+1)){
			board[row][col] = a+1;
			if(solveSuduko(board, row, col+1)){
				return true;
			}
		}
		board[row][col] = 0;
	}
	return false;
}

int main(){
	int board[N][N] = {
		{ 1, 0, 0, 0, 0, 4, 0, 6, 0 },
		{ 0, 0, 8, 0, 0, 0, 3, 0, 0 },
		{ 6, 5, 0, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 4, 0, 0, 8, 7, 3 },
		{ 9, 0, 0, 0, 1, 0, 0, 2, 0 },
		{ 2, 0, 0, 8, 0, 0, 0, 0, 9 },
		{ 4, 0, 0, 5, 0, 6, 0, 0, 0 },
		{ 0, 9, 1, 0, 0, 0, 0, 0, 5 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};
	if(solveSuduko(board, 0, 0)){
		printBoard(board);
	}else{
    printf("No Solution\n");
  }
	return 0;
}

bool isSafe(int board[N][N], int row, int col, int num){
	for(int a = 0; a < N; a++){
		if(board[row][a] == num){
			return false;
		}
		if(board[a][col] == num){
			return false;
		}
	}
	int start_row = row - row % 3;
	int start_col = col - col % 3;
	for(int a = 0; a < 3; a++){
		for(int b = 0; b < 3; b++){
			if(board[a + start_row][b + start_col] == num){
				return false;
			}
		}
	}
	return true;
}

void printBoard(int arr[N][N]){
	for(int a = 0; a < N; a++){
		for(int b = 0; b < N; b++){
			printf("%d ", arr[a][b]);
		}
		printf("\n");
	}
	printf("\n");
}
