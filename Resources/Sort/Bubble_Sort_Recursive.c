#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);
void swap(int *a, int *b);

void recursiveBubbleSort(int arr[], int k, int n){
	if(n <= 0){
		return;
	}else if(k >= n){
		return recursiveBubbleSort(arr, 0, n-1);
	}
	if(k+1 < n && arr[k] > arr[k+1]){
		swap(&arr[k], &arr[k+1]);
	}
	recursiveBubbleSort(arr, k+1, n);
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	recursiveBubbleSort(arr, 0, N);
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
