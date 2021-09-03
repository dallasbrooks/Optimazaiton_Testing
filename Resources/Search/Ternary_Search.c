#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25

void printArray(int arr[], int n);

int ternarySearch(int arr[], int l, int r, int x){
	if(l > r){
		return -1;
	}
	int m1 = l + (r-l) / 3;
	int m2 = r - (r-l) / 3;
	if(arr[m1] == x){
		return m1;
	}else if(arr[m2] == x){
		return m2;
	}
  return x < arr[m1] ? ternarySearch(arr, l, m1-1, x) : x > arr[m2] ? ternarySearch(arr, m2+1, r, x) : ternarySearch(arr, m1+1, m2-1, x);
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
	int idx = ternarySearch(arr, 0, N-1, x);
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
