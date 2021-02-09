#include<stdio.h>
int binary_search(int arr[], int l, int h, int key)
{
    int mid;
    if (l>h)
        return -1;
    mid=(l+h)/2;
    if (arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        binary_search(arr,l,mid-1,key);
    else if(arr[mid]<key)
        binary_search(arr,mid+1,h,key);
}
void main()
{
    int arr[6]={1,2,3,4,5,6};
    printf("%d",binary_search(arr,0,5,-7));
}