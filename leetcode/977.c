/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high){
     int pivot=arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i=(low-1);
   
  for(int j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(&arr[i],&arr[j]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i+1);
}

void quick_sort(int arr[], int l, int h){
    if(l<h){
        int pivot = partition(arr, l, h);
        quick_sort(arr, l, pivot-1);
        quick_sort(arr, pivot+1, h);
    }
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *p = (int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++){
        p[i] = nums[i]*nums[i];
    }
    quick_sort(p, 0, numsSize-1);
    return p;
}