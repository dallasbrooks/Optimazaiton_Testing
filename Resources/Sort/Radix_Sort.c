#include <stdio.h>

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
	printArray(arr, n);
}

int main(){
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_length);
	radixSort(arr, arr_length);
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
