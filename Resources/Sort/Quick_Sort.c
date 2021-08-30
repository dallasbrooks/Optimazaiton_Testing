#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);
void swap(int *a, int *b);
int partition(int arr[], int l, int h);

void quickSort(int arr[], int l, int h){
	if(l >= h){
		return;
	}
	printArray(arr, l+1);
	int part = partition(arr, l, h);
	quickSort(arr, l, part-1);
	quickSort(arr, part+1, h);
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	quickSort(arr, 0, N-1);
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

int partition(int arr[], int l, int h){
	int pivot = arr[h];
	int a = l-1;
	for(int b = l; b <= h; b++){
		if(arr[b] < pivot){
			a++;
			swap(&arr[a], &arr[b]);
		}
	}
	swap(&arr[a+1], &arr[h]);
	return a+1;
}
