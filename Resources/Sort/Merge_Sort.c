#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 25
#define M 250

void printArray(int arr[], int n);
void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r){
	if(l >= r){
		return;
	}
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	merge(arr, l, m, r);
}

int main(){
	srand(time(NULL));
	int arr[N] = {0};
	for(int a = 0; a < N; a++){
		arr[a] = rand()%M;
	}
	printArray(arr, N);
	mergeSort(arr, 0, N-1);
	printArray(arr, N);
	return 0;
}

void printArray(int arr[], int n){
	for(int a = 0; a < n; a++){
		printf("%d ", arr[a]);
	}
	printf("\n");
}

void merge(int arr[], int l, int m, int r){
  int Ln = m - l + 1;
	int Rn = r - m;
	int L[Ln];
	int R[Rn];
	for(int a = 0; a < Ln || a < Rn; a++){
	    if(a < Ln){
	        L[a] = arr[l + a];
	    }
	    if(a < Rn){
	        R[a] = arr[m + 1 + a];
	    }
	}
	int ll = 0;
	int rr = 0;
	for(int a = l; a < l+r+1; a++){
	    if(ll < Ln && rr < Rn){
	        arr[a] = L[ll] <= R[rr] ? L[ll++] : R[rr++];
	    }else if(ll < Ln || rr < Rn){
	        arr[a] = ll < Ln ? L[ll++] : R[rr++];
	    }
	}
}
