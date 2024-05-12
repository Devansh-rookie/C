#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>


void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr , int lb , int ub){
    // let the Pivot first be the last index
    int pivot = arr[ub];
    int pIndex=lb;
    for(int i=lb;i<ub;i++){
        if(arr[i]<pivot){
            swap(&arr[i],&arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[pIndex], &arr[ub]);
    return pIndex;
}

void quickSort(int *arr, int lb, int ub){
    if(ub>lb){
        int pIndex = partition(arr, lb, ub);// partition index
        quickSort(arr, lb, pIndex-1);
        quickSort(arr, pIndex+1, ub);
    }
}

void print(int arr[], int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {214,1,4,215,1345,314,6,1346,1,36};
    quickSort(arr, 0, 9);
    print(arr,10);
    return 0;
}

