#include<stdio.h> 
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
}
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 
int main() 
{ 
	int arr[] = {10, 7, 8, 9, 1, 5}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	quickSort(arr, 0, n-1); 
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
} 

/* #include<stdio.h>
void quickSort(int arr[], int l, int r){
    if(r-l<=1) return;
    int yellow=l+1,green;
     for(green=l+1;green<=r;green++){
        if(arr[green]<=arr[l]){
            arr[yellow]=arr[yellow]+arr[green];
            arr[green]=arr[yellow]-arr[green];
            arr[yellow]=arr[yellow]-arr[green];
            yellow++;
        }
    } 
    //int arr[6]={5,2,8,6,1,4};
    // 5 2 4 1 6 8
    for(green=r;1;green--){
        if(arr[green]<=arr[l]){
            arr[yellow]=arr[yellow]+arr[green];
            arr[green]=arr[yellow]-arr[green];
            arr[yellow]=arr[yellow]-arr[green];
            yellow++;
        }
        if(yellow>green-1)
            break;
        if(arr[green]<=arr[l])
            green++;
    }
    arr[l]=arr[l]+arr[yellow-1];
    arr[yellow-1]=arr[l]-arr[yellow-1];
    arr[l]=arr[l]-arr[yellow-1];
    quickSort(arr, l, yellow-2);
    quickSort(arr, yellow, r);
}
void main(){
    int arr[6]={5,2,8,6,1,4};
    //quickSort(arr,0,5);
    //int arr[3]={2,1,3};
    quickSort(arr, 0,5);
    for(int i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
} */