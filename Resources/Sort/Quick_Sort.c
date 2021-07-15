#include <stdio.h>

void printArray(int arr[], int n);
void swap(int *a, int *b);
int partition(int arr[], int l, int h);

void quickSort(int arr[], int l, int h){
	printArray(arr, l+1);
	if(l < h){
		int part = partition(arr, l, h);
		quickSort(arr, l, part-1);
		quickSort(arr, part+1, h);
	}
}

int main(){
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_length);
	quickSort(arr, 0, arr_length-1);
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
