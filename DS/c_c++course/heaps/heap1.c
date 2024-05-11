#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int * insertInHeap(int* heap, int val, int *size){
    // (*size) = *size +1;
    // int index = *size;
    heap[++(*size)] = val;
    int index = *size;
    while (index>1)
    {
        int parent = index/2;
        if(heap[parent]<heap[index]){
            swap(&heap[parent],&heap[index]);
            index = parent;
        }
        else{
            return heap;
        }
    }
    return heap;
}

void print(int * arr, int size){
    printf("\n");
    for(int i=1;i<=size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
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

void deleteFromHeap(int * heap, int val,int *size){
    if(*size==0){
        printf("\nEmpty heap\n");
        return;
    }
    int index=1;
    for(int i=1;i<=*size;i++){
        if(heap[i]== val){
            index = i;
            break;
        }
    }
    swap(&heap[index], &heap[*size]);
    *size = *size - 1;
    max_heapify(heap, index, *size);
}

int main(){
    int heap[100];
    int size = 0;
    heap[0] = -1;
    // insertInHeap(heap,100,&size);
    // insertInHeap(heap,20,&size);
    // insertInHeap(heap,10,&size);
    // insertInHeap(heap,110,&size);
    insertInHeap(heap,50,&size);
    insertInHeap(heap,55,&size);
    insertInHeap(heap,53,&size);
    insertInHeap(heap,52,&size);
    insertInHeap(heap,54,&size);
    insertInHeap(heap,62,&size);
    insertInHeap(heap,14,&size);
    print(heap, size);
    max_heapify(heap, 1, size);
    print(heap, size);
    deleteFromHeap(heap, 62, &size);
    print(heap,size);
    deleteFromHeap(heap, 55, &size);
    print(heap,size);
    return 0;
}
