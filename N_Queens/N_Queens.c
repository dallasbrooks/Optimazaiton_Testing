#include <stdio.h>
#include <stdbool.h>

#define Qn 4

void printBoard(int board[Qn][Qn]);
void showStep(int board[Qn][Qn], int row, int col);
bool isSafe(int board[Qn][Qn], int row, int col);

bool solveBoard(int board[Qn][Qn], int col){
	if(col >= Qn){
		return true;
	}
	for(int a = 0; a < Qn; a++){
		showStep(board, a, col);
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
	int board[Qn][Qn] = {0};
	if(solveBoard(board, 0) == false){
		printf("No Solution\n");
		return 0;
	}
	printBoard(board);
	return 0;
}

bool isSafe(int board[Qn][Qn], int row, int col){
	int a;
	int b;
	for(a = 0; a < Qn; a++){
		if(board[row][a]){
			return false;
		}
	}
	for(a = row, b = col; a >= 0 && b >= 0; a--, b--){
		if(board[a][b]){
			return false;
		}
	}
	for(a = row, b = col; a < Qn && b >= 0; a++, b--){
		if(board[a][b]){
			return false;
		}
	}
	return true;
}

void printBoard(int board[Qn][Qn]){
	for(int a = 0; a < Qn; a++){
		for(int b = 0; b < Qn; b++){
			printf("%d ", board[a][b]);
		}
		printf("\n");
	}
	printf("\n");
}

void showStep(int board[Qn][Qn], int row, int col){
	board[row][col] = 1;
	printBoard(board);
	board[row][col] = 0;
}
