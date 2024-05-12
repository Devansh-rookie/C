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

int firstPartition(int * arr, int lb, int ub){
    // int pIndex = lb;
    int pivot = arr[lb];
    int i=lb+1, j=ub;
    while (true)
    {
        while(i<=j && arr[i]<pivot){// condition to be satisfied to place the value of the pivot at the middle and return its index
            i++;
        }
        while(i<=j && arr[j]>pivot){
            j--;
        }
        if(j<=i) break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[lb], &arr[j]);
    return j; // j is the required position of the pivot in the middle, left has everything smaller than it and the right has everything bigger than it so in the end it makes it sorted are we do it for all points more or less.
}

void quickSortFirst(int * arr, int lb, int ub){
    if(ub>lb){
        int pIndex = firstPartition(arr, lb, ub);
        quickSortFirst(arr, lb, pIndex-1);
        quickSortFirst(arr, pIndex+1, ub);
    }
    return;
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

    int arr2[] = {214,1,4,215,1345,314,6,1346,1,36};
    quickSortFirst(arr2, 0 ,9);
    print(arr, 10);
    return 0;
}

