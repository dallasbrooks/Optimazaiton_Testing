#include <stdio.h>

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
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_length);
	recursiveInsertionSort(arr, arr_length);
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