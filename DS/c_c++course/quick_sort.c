#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void qsort(){
    
}

int main(){
    int arr[]= {3,1,2,4,5,8,9};
    // qsort(arr,0,3,6);
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
