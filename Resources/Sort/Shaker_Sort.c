#include <stdio.h>

void printArray(int arr[], int n);
void swap(int *a, int *b);

void shakerSort(int arr[], int n){
    int swapped = 1;
    int start = 0;
    int end = n-1;
    while(swapped){
        swapped = 0;
        for(int a = start; a < end; a++){
            if(arr[a] > arr[a+1]){
                swap(&arr[a], &arr[a+1]);
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
        swapped = 0;
        end--;
        for(int a = end-1; a >= start; a--){
            if(arr[a] > arr[a+1]){
                swap(&arr[a], &arr[a+1]);
                swapped = 1;
            }
        }
        start++;
        printArray(arr, n);
    }
}

int main(){
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_length);
	shakerSort(arr, arr_length);
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
