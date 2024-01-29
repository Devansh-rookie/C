#include<stdio.h>

void merge(int a[], int l, int mid, int h){
    int i,j,k;
    int b[100];
    i=l;j=mid+1;k=l;
    while(i<=mid && j<=h){
        if(a[i]>=a[j]){
            b[k]=a[j];
            k++;j++;
        }
        else{
            b[k]=a[i];
            i++;k++;
        }
    }
    while (i<=mid)
    {
        b[k]=a[i];
        k++;i++;
    }
    while (j<=h)
    {
        b[k]=a[j];
        k++;j++;
    }
    for(int c=0;c<=h;c++){
        a[c]=b[c];
    }
}

void merge_sort(int a[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        merge_sort(a, l, mid);
        merge_sort(a,mid+1,h);
        merge(a,l, mid, h);
    }
}

int main(){
    int arr[]= {3,1,2,4,5,8,9};
    merge_sort(arr,0,6);
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
