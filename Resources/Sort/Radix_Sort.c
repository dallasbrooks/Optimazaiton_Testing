#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);
void countSort(int arr[], int n, int exp);

void radixSort(int arr[], int n){
	int max = arr[0];
	for(int a = 0; a < n; a++){
		if(arr[a] > max){
			max = arr[a];
		}
	}
	for(int exp = 1; max / exp > 0; exp *= 10){
		countSort(arr, n, exp);
	}
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	radixSort(arr, N);
	printArray(arr, N);
	return 0;
}

void printArray(int arr[], int n){
	for(int a = 0; a < n; a++){
		printf("%d ", arr[a]);
	}
	printf("\n");
}

void countSort(int arr[], int n, int exp){
	int result[n];
	int count[10] = {0};
	for(int a = 0; a < n; a++){
		count[(arr[a] / exp) % 10]++;
	}
	for(int a = 1; a < 10; a++){
		count[a] += count[a-1];
	}
	for(int a = n-1; a >= 0; a--){
		result[count[(arr[a] / exp) % 10] - 1] = arr[a];
		count[(arr[a] / exp) % 10]--;
	}
	for(int a = 0; a < n; a++){
		arr[a] = result[a];
	}
}
