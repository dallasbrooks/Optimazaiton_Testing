#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

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
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	slowSort(arr, 0, N-1);
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
