#include <stdio.h>

void printArray(int arr[], int n);
void merge(int arr[], int l, int m, int r);

void mergeSort(int arr[], int l, int r){
	if(l < r){
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
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
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for(i = 0; i < n1; i++){
		L[i] = arr[l + i];
	}
	for(j = 0; j < n2; j++){
		R[j] = arr[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}
39 Resources/Sort/Selection_Sort.c
@@ -0,0 +1,39 @@
#include <stdio.h>

void printArray(int arr[], int n);
void swap(int *a, int *b);

void selectionSort(int arr[], int n){
	int min = 0;
	for(int a = 0; a < n-1; a++){
		min = a;
		for(int b = a+1; b < n; b++){
			if(arr[b] < arr[min]){
				min = b;
			}
		}
		swap(&arr[min], &arr[a]);
		printArray(arr, n);
	}
}

int main(){
	int arr[] = {21, 26, 13, 5, 29, 6, 12, 9, 20, 19, 14, 17, 15, 22, 18, 24, 27, 4, 16, 30, 2, 7, 25, 11, 10};
	int arr_length = sizeof(arr)/sizeof(arr[0]);
	printArray(arr, arr_length);
	selectionSort(arr, arr_length);
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
