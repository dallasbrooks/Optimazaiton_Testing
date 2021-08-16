#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 2

int arr[N] = {0};

void printArray(int k);

void iterate(int count[]){
	for(int a = 0; a < N; a++) {
		arr[a] = count[N-1-a]+1;
	}
	printArray(0);
	count[0]++;
	for(int a = 0; a < N && count[a] == M; a++){
		if(a == N-1){
			return;
		}
		count[a] = 0;
		count[a+1]++;
	}
	iterate(count);
}

int main(){
	int count[N] = {0};
	iterate(count);
	return 0;
}

void printArray(int k){
	if(k >= N){
		printf("\n");
		return;
	}
	printf("%d ", arr[k]);
	printArray(k + 1);
}
