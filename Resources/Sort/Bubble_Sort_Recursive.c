#include <stdio.h>

void printArray(int arr[], int n);
void swap(int *a, int *b);

void bubbleSort(int arr[], int n){
	if(n <= 1){
		return;
	}
	int swapped = 0;
	for(int a = 0; a < n-1; a++){
		if(arr[a] > arr[a+1]){
			swap(&arr[a], &arr[a+1]);
			swapped = 1;
		}
	}
	if(swapped){
		bubbleSort(arr, n-1);
	}
}

int main(){
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_length);
	bubbleSort(arr, arr_length);
	printArray(arr, arr_length);
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