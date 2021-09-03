#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

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
        for(int a = end; a > start; a--){
            if(arr[a] < arr[a-1]){
                swap(&arr[a], &arr[a-1]);
                swapped = 1;
            }
        }
        start++;
        printArray(arr, n);
    }
}

int main(){
	srand(time(NULL));
    int arr[N] = {0};
    for(int a = 0; a < N; a++){
        arr[a] = rand()%M;
    }
    printArray(arr, N);
	shakerSort(arr, N);
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
