#include<stdio.h>

void actual_sorting(int arr[], int key, int j){
    if(arr[j]>key&& j>=0){
        arr[j+1]= arr[j];
        actual_sorting(arr, key, j-1);
    }
    // arr[j+1]= key; its a mistake as we only exchange this value when its not true not every time that the function is run
    else arr[j+1]= key;
}

void insertion_recursive(int arr[], int i,int size){
    if(i<size){
        actual_sorting(arr,arr[i],i-1);
        insertion_recursive(arr, i+1,size);
    }
}

void print_arr(int arr[], int n){
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

int main(){
    // int arr[5] = { 12, 11, 13, 5, 6 };
    // start i from 1 as we are using i-1 there
    int n;
    printf("What is n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Values: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    insertion_recursive(arr, 1, n);
    print_arr(arr,n);
    return 0;
}
