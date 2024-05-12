#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>

void merge(int arr[], int lb, int mid, int ub){
    int i=lb;
    int j= mid+1;
    int k= 0;
    int b[100];

    while(i<=mid && j<=ub){
        if(arr[i]>arr[j]){
            b[k++]= arr[j++];
        }
        else{
            b[k++]= arr[i++];
        }
    }

    while (i<=mid)
    {
        b[k++] = arr[i++];
    }
    
    while(j<=ub){
        b[k++] = arr[j++];
    }

    for(int c=0;c<=ub-lb;c++){
        arr[c+lb] = b[c];
    }
}

void mergeSort(int arr[], int lb, int ub){
    // int mid;
    if(ub>lb){
        int mid = (lb+ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
    else return;
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
    mergeSort(arr, 0, 9);
    print(arr,10);
    return 0;
}
