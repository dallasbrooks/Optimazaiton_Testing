#include <stdio.h>

void printArray(int arr[], int n);

int binarySearch(int arr[], int l, int r, int x){
    if (r >= l) {
        int m = l + (r - l) / 2;
        if(arr[m] == x){
            return m;
            
        }else if(arr[m] > x){
            return binarySearch(arr, l, m-1, x);
        }else{
          return binarySearch(arr, m+1, r, x);
        }
    }
    return -1;
}

int main(){
	int arr[] = {2, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 25, 26, 27, 29, 30};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	int x = 18;
	printArray(arr, arr_length);
	printf("Looking for %d\n", x);
	int idx = binarySearch(arr, 0, arr_length-1, x);
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
