#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high){
    int pivot= arr[low];
    int i= low+1;
    int j = high;
    while(1){
        while(i<=j && arr[i]<pivot){
            i++;
        }
        while(i<=j && arr[j]>pivot){
            j--;
        }
        if(j<i) break;
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return (j);
}

void quick_sort(int arr[], int low, int high){
    if(low< high){
        int pivot = partition(arr,low,high);
        quick_sort(arr,low, pivot-1);
        quick_sort(arr, pivot+1, high);
    }
}

int main(){
    int n;
    printf("What is n: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quick_sort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
