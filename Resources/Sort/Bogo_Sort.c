#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 250

void printArray(int arr[], int n);
void swap(int *a, int *b);
int isSorted(int arr[], int k, int n);

void bogoSort(int arr[], int n){
	for(int a = 0; a < n/2; a++){
		swap(&arr[a], &arr[rand()%n]);
	}
	return isSorted(arr, 0, n) ? NULL : bogoSort(arr, n);
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	bogoSort(arr, N);
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

int isSorted(int arr[], int k, int n){
	return k+1 >= n ? 1 : arr[k] > arr[k+1] ? 0 : isSorted(arr, k+1, n);
}
