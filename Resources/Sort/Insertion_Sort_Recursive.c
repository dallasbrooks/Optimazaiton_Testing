#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);
void swap(int *a, int *b);

void recursiveInsertionSort(int arr[], int n){
	if(n <= 0){
		return;
	}
	recursiveInsertionSort(arr, n-1);
	int key = arr[n-1];
	int a = n-2;
	while(a >= 0 && arr[a] > key){
		arr[a+1] = arr[a];
		a--;
	}
	arr[a+1] = key;
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	recursiveInsertionSort(arr, N);
	printArray(arr, N);
	return 0;
}

void printArray(int arr[], int n){
	for(int a = 0; a < n; a++){
		printf("%d ", arr[a]);
	}
	printf("\n");
}

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}