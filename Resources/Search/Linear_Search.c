#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);

int linearSearch(int arr[], int n, int x){
	for(int a = 0; a < n; a++){
		if(arr[a] == x){
			return a;
		}
	}
	return -1;
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	int x = arr[rand()%N];
	printArray(arr, N);
	printf("Looking for %d\n", x);
	int idx = linearSearch(arr, N, x);
	if(idx != -1){
		printf("Found %d at index %d\n", x, idx);
	}else{
		printf("Did not find %d\n", x);
	}
	return 0;
}

void printArray(int arr[], int n){
	for(int a = 0; a < n; a++){
		printf("%d ", arr[a]);
	}
	printf("\n");
}
