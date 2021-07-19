#include <stdio.h>

void printArray(int arr[], int n);

void insertionSort(int arr[], int n){
	int min = 0;
	for(int a = 1; a < n; a++){
		min = arr[a];
		int b = a-1;
		while(b >= 0 && arr[b] > min){
			arr[b+1] = arr[b];
			b--;
		}
		arr[b+1] = min;
		printArray(arr, n);
	}
}

int main(){
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_length);
	insertionSort(arr, arr_length);
	return 0;
}

void printArray(int arr[], int n){
	for(int a = 0; a < n; a++){
		printf("%d ", arr[a]);
	}
	printf("\n");
}
