
#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>


void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void min_heapify(int * heap, int index, int size){
    int lIndex = index*2;
    int rIndex = index*2+1;
    if(size== 0) return;
    if(((lIndex<=size && heap[index]<heap[lIndex])|| lIndex>size)&&((rIndex<=size && heap[index]<heap[rIndex])|| rIndex>size)){
        return;
    }
    if(lIndex<=size && heap[index]>heap[lIndex]){
        swap(&heap[index], &heap[lIndex]);
        min_heapify(heap, lIndex, size);
    }
    if(rIndex<=size && heap[index]>heap[rIndex]){
        swap(&heap[index], &heap[rIndex]);
        min_heapify(heap, rIndex, size);
    }
    return;
}


int * insertInHeap(int* heap, int val, int *size){
    // (*size) = *size +1;
    // int index = *size;
    heap[++(*size)] = val;
    int index = *size;
    while (index>1)
    {
        int parent = index/2;
        if(heap[parent]>heap[index]){
            swap(&heap[parent],&heap[index]);
            index = parent;
        }
        else{
            return heap;
        }
    }
    return heap;
}

void deleteFromHeap(int * heap, int index,int *size){
    if(*size==0){
        // printf("\nEmpty heap\n");
        return;
    }
    // int index=1;
    // for(int i=1;i<=*size;i++){
    //     if(heap[i]== val){
    //         index = i;
    //         break;
    //     }
    // }
    swap(&heap[index], &heap[*size]);
    *size = *size - 1;
    min_heapify(heap, index, *size);
}

// Kth Largest Element
int kthLargest(int * heap, int size, int k){
    // int newHeap1[size];
    int * newHeap1 = (int*)malloc(sizeof(int)*(size+1));
    newHeap1[0]=0;
    int newSize1 =0;

    for(int i=0;i<k;i++){
        insertInHeap(newHeap1,heap[i],&newSize1);
    }

    for(int i=k;i<size;i++){
        // insertInHeap(newHeap2,heap[i],&newSize2);
        if(newHeap1[1]<heap[i]){
            // deleteFromHeap(newHeap1, 1, &newSize1);
            // insertInHeap(newHeap1, heap[i],&newSize1);
            newHeap1[1]= heap[i];
            min_heapify(newHeap1, 1, k);
        }
    }
    return newHeap1[1];
}

int findKthLargest(int* nums, int numsSize, int k) {
    if(numsSize ==1) return nums[0];
    return kthLargest(nums, numsSize, k);
}

int main(){
    int arr[5]= {124,532,1,15,21};
    printf("%d ",findKthLargest(arr,5,3));
    return 0;
}