#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void max_heapify(int * heap, int index, int size){
    int lIndex = index*2;
    int rIndex = index*2+1;
    if(size== 0) return;
    if(((lIndex<=size && heap[index]>heap[lIndex])|| lIndex>size)&&((rIndex<=size && heap[index]>heap[rIndex])|| rIndex>size)){
        return;
    }
    if(lIndex<=size && heap[index]<heap[lIndex]){
        swap(&heap[index], &heap[lIndex]);
        max_heapify(heap, lIndex, size);
    }
    if(rIndex<=size && heap[index]<heap[rIndex]){
        swap(&heap[index], &heap[rIndex]);
        max_heapify(heap, rIndex, size);
    }
    return;
}

void print(int * arr, int size){
    printf("\n");
    for(int i=1;i<=size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// Using MaxHeap doing Ascending Sort
void heapSort(int * heap , int size){
    while(size>=1){
        swap(&heap[1], &heap[size]);
        size--;
        max_heapify(heap,1,size);
    }
}

int main(){
    int arr[11] = {0,14,234,521,1,51,5,15351,513,124,123};
    int size = 10;
    for(int i=size/2+1;i>=1;i--){
        max_heapify(arr,i,size);
    }
    print(arr, size);
    heapSort(arr, size);
    print(arr, size);
    return 0;
}


