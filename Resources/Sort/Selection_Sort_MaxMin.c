#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);
void swap(int *a, int *b);
int isSorted(int arr[], int k, int n);

void maxminSelectionSort(int arr[], int k, int n){
    if(k >= n){
        return;
    }
    int min = k;
    int max = n;
    for(int a = k; a <= n; a++){
        if(arr[a] < arr[min]){
            min = a;
        }
        if(arr[a] > arr[max]){
            max = a;
        }
    }
    max = max == k ? min : max;
	swap(&arr[k], &arr[min]);
	swap(&arr[n], &arr[max]);
	maxminSelectionSort(arr, k+1, n-1);
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	maxminSelectionSort(arr, 0, N-1);
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