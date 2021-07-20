#include <stdio.h>

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
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_length);
	mergeSort(arr, 0, arr_length-1);
	printArray(arr, arr_length);
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
	for(int a = 0; a < Ln; a++){
		L[a] = arr[l + a];
	}
	for(int a = 0; a < Rn; a++){
		R[a] = arr[m + 1 + a];
	}
	int ll = 0;
	int rr = 0;
	for(int a = l; a < l+r+1; a++){
		if(ll < Ln && rr < Rn){
			if(L[ll] <= R[rr]){
				arr[a] = L[ll];
				ll++;
			}else{
				arr[a] = R[rr];
				rr++;
			}
		}else if(ll < Ln){
			arr[a] = L[ll];
			ll++;
		}else if(rr < Rn){
			arr[a] = R[rr];
			rr++;
		}
	}
}
