#include<stdio.h>
int lenLongestFibSubseq(int* arr, int arrSize) {
    int n=arrSize;
    int i,j,count=2;
    for(i=0;i<n-1&&arr[i]+arr[j]<=arr[n-1];i++){
        for(j=i+1;j<n-1;j++){
            for(int k=j+1;k<n-1;k++){
                if(arr[i]+arr[j]==arr[k]) count++;
            }
        }
    }
    printf("%d",count);
}
int main(){
    int arr[5]= {1,2,3,4,5};
    lenLongestFibSubseq(arr,5);
    return 0;
}