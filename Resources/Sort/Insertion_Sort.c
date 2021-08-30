#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);

void insertionSort(int arr[], int n){
	for(int a = 1; a < n; a++){
		int min = arr[a];
		int b = a-1;
		while(b >= 0 && arr[b] > min){
			arr[b+1] = arr[b];
			b--;
		}
		arr[b+1] = min;
	}
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	insertionSort(arr, N);
	printArray(arr, N);
	return 0;
}

void printArray(int arr[], int n){
	for(int a = 0; a < n; a++){
		printf("%d ", arr[a]);
	}
	printf("\n");
}
