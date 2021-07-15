#include <stdio.h>

void printArray(int arr[], int n);

int linearSearch(int arr[], int n, int x){
	for(int a = 0; a < n; a++){
		if(arr[a] == x){
			return a;
		}
	}
	return -1;
}

int main(){
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	int x = 18;
	printArray(arr, arr_length);
	printf("Looking for %d\n", x);
	int idx = linearSearch(arr, arr_length, x);
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