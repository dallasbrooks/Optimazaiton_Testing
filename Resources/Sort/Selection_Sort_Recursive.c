#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);
void swap(int *a, int *b);

void recursiveSelectionSort(int arr[], int n){
	if(n <= 1){
		return;
	}
	int min = 0;
	for(int a = 0; a < n; a++){
		if(arr[a] < arr[min]){
			min = a;
		}
	}
	if(min != 0){
		swap(&arr[0], &arr[min]);
	}
	recursiveSelectionSort(arr+1, n-1);
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	recursiveSelectionSort(arr, N);
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