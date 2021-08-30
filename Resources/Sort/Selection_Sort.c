#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);
void swap(int *a, int *b);

void selectionSort(int arr[], int n){
	for(int a = 0; a < n-1; a++){
		int min = a;
		for(int b = a+1; b < n; b++){
			if(arr[b] < arr[min]){
				min = b;
			}
		}
		swap(&arr[min], &arr[a]);
		printArray(arr, n);
	}
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	selectionSort(arr, N);
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
