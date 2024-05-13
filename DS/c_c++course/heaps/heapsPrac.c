#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>

#define maxSize 100


void printHeap(int *heap, int size){
    printf("\n");
    for(int i=1;i<=size;i++) printf("%d ", heap[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int * heap, int index ,int size){
    int lIndex = 2*index;
    int rIndex = 2*index+1;

    if(((lIndex<=size && heap[lIndex]<heap[index])||(lIndex>size))&&((lIndex<=size && heap[rIndex]<heap[index])||(rIndex>size))){
        return;
    }
    if(heap[index]<heap[lIndex]){
        swap(&heap[index],&heap[lIndex]);
        maxHeapify(heap, lIndex, size);
    }
    if(heap[index]<heap[rIndex]){
        swap(&heap[index],&heap[rIndex]);
        maxHeapify(heap, rIndex, size);
    }
    return;
}

int * insertInMaxHeap(int *heap, int *size, int val){
    heap[++(*size)] = val;
    int index = *size;
    while(index>=1){
        int parent = index/2;
        if(heap[index]>heap[parent]){
            swap(&heap[index], &heap[parent]);
            index = parent;
        }
        else{
            return heap;
        }
    }
    return heap;
}

void deletefromIndex(int * heap, int *size, int index){
    swap(&heap[index], &heap[*size]);
    (*size)--;
    maxHeapify(heap, index, *size);
}

void heapSort(int *heap, int size){// Ascending Order
    while(size>=1){
        swap(&heap[1], &heap[size]);
        size--;
        maxHeapify(heap, 1, size);
    }
}

void heapifyArr(int *arr, int size){
    for(int i=size/2; i>=1;i--){
        maxHeapify(arr, i, size);
    }
}

int main(){
    int heap[maxSize];
    int size =0;
    int arr[11] = {0,14,234,521,1,51,5,15351,513,124,123};
    printHeap(arr, 10);
    heapifyArr(arr, 10);
    printHeap(arr, 10);
    heapSort(arr, 10);
    printHeap(arr, 10);
    return 0;
}
