#include<stdio.h>

void display(int arr[],int n){// or pointers can be used
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int arr[],int n){// or pointers can be used instead of arr
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=1;j<=n-i;j++){
    //         if(arr[j]<arr[j-1]){
    //             // swap(&arr[i],&arr[j]);
    //             int temp = arr[j-1];
    //             arr[j-1]= arr[j];
    //             arr[j]= temp;
    //         }
    //     }
    // }
    display(arr,n);
}

void selection_sort(int arr[], int n){
    for(int i=0;i<n;i++){
        int min_index=i;// set the index of the minimum value to be i and then go on ...
        for(int j=i+1;j<n;j++){// from i+1 as till the values are already sorted
            if(arr[j]<arr[min_index]) min_index=j;
        }
        swap(&arr[min_index],&arr[i]);// arr[i] would be swapped with min index as it would make an ascending array
    }
    display(arr,n);
}

int main(){
    int n;
    printf("Number of elements to input: ");
    scanf("%d",&n);
    int arr[n];
    printf("What are the values of the array: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    bubble_sort(arr,n);
    selection_sort(arr,n);
    return 0;
}
