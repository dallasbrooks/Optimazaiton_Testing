#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25

void printArray(int arr[], int n);

int binarySearch(int arr[], int l, int r, int x){
	if(l > r){
		return -1;
	}
	int m = (l + r) / 2;
	if(arr[m] == x){
		return m;
	}
	return arr[m] > x ? binarySearch(arr, l, m-1, x) : binarySearch(arr, m+1, r, x);
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = a;
	}
	int x = arr[rand()%N];
	printArray(arr, N);
	printf("Looking for %d\n", x);
	int idx = binarySearch(arr, 0, N-1, x);
	if(idx != -1){
		printf("Found %d at index %d\n", x, idx);
	}else{
		printf("Did not find %d\n", x);
	}
	return 0;
}

void printArray(int arr[], int n){
	for(int a = 0; a < n; a++){
		printf("%d ", arr[a]);
	}
	printf("\n");
}
