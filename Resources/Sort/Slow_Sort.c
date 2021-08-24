#include <stdio.h>

void printArray(int arr[], int n);
void swap(int *a, int *b);

void slowSort(int arr[], int l, int r){
	if(l >= r){
		return;
	}
	int m = (l+r) / 2;
	slowSort(arr, l, m);
	slowSort(arr, m+1, r);
	if(arr[m] > arr[r]){
		swap(&arr[m], &arr[r]);
	}
	slowSort(arr, l, r-1);
}

int main(){
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_length);
	slowSort(arr, 0, arr_length-1);
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
