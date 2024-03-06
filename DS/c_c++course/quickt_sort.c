#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high){

    int pivot = arr[high];
    int i=low-1;// i pivot ke liye hai

    for(int j=low;j<=high;j++){
        if(arr[j]<pivot){// chhota hai toh peeche late/karte raho
            i++;
            swap(&arr[i],&arr[j]);
        }
        // else do nothing absolutely noything bada ho toh chod do
    }
    swap(&arr[i+1],&arr[high]);// pivot ko position main lana
    return (i+1);
}

void quick_sort(int arr[], int low, int high){
    if(low<high){
        int pivot = partition(arr, low, high);
        quick_sort(arr,low, pivot-1);// pivot is not included in either of the numbers
        quick_sort(arr, pivot+1, high);
    }
}

int main(){
    int n;
    printf("What is n: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quick_sort(arr, 0, n-1);// by taking last element as pivot now we will do it by taking first element as pivot that would mean that we would have to change the numbers such that the smaller numbers would remain at the same place while the larger elements would be shifted to the right which is the exact opposite of what we have done in this code

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
