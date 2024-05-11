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

// Kth Smallest Element
int kthSmallest(int * heap, int size, int k){
    int newHeap1[100];
    newHeap1[0]=0;
    int newSize1 =0;

    for(int i=1;i<=k;i++){
        insertInHeap(newHeap1,heap[i],&newSize1);
    }

    for(int i=k+1;i<=size;i++){
        // insertInHeap(newHeap2,heap[i],&newSize2);
        if(newHeap1[1]>heap[i]){
            deleteFromHeap(newHeap1, newHeap1[1], &newSize1);
            insertInHeap(newHeap1, heap[i],&newSize1);
        }
    }
    return newHeap1[1];
}

int main(){
    int size =0;
    int heap[100];
    insertInHeap(heap, 7, &size);
    insertInHeap(heap, 10, &size);
    insertInHeap(heap, 4, &size);
    insertInHeap(heap, 3, &size);
    insertInHeap(heap, 3, &size);
    insertInHeap(heap, 3, &size);
    insertInHeap(heap, 3, &size);
    insertInHeap(heap, 20, &size);
    insertInHeap(heap, 15, &size);
    // insertInHeap(heap, 9, &size);

    print(heap, size);
    int k=3;
    printf("\n%dth Smallest element is: %d\n",k,kthSmallest(heap, size, k));
    return 0;
}