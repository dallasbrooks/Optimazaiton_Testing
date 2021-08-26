#include <stdio.h>

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
	if(x < arr[m1]){
		return ternarySearch(arr, l, m1-1, x);
	}else if(x > arr[m2]){
		return ternarySearch(arr, m2+1, r, x);
	}else{
		return ternarySearch(arr, m1+1, m2-1, x);
	}
}

int main(){
	int arr[] = {2, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 27, 29, 30};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	int x = 18;
	printArray(arr, arr_length);
	printf("Looking for %d\n", x);
	int idx = ternarySearch(arr, 0, arr_length-1, x);
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
