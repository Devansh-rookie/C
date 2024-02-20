#include<stdio.h>

void display(int arr[], int n){
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

void binary_search(int arr[],int n){
    int start = 0;
    int last = n-1;
    int flag =0;
    int mid = (start +last)/2;
    int key;
    printf("What to search:");
    scanf("%d",&key);
    while(start<=last){
        mid = (start +last)/2;
        if(arr[mid]==key){
            printf("The value is found at index %d.",mid);
            flag =1;
            break;
        }
        else if(arr[mid]>key){
            last = mid-1;
        }
        else{
            start = mid +1;
        }
    }
    if(!flag) printf("Value not found.");
}

void merge(int arr[], int l, int mid, int h){
    int b[100];
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=h){
        if(arr[i]>=arr[j]){
            b[k]= arr[j];// smaller wala put as that array would be sorted as we are using the merger sorting technique
            k++;j++;
        }
        else{
            b[k]= arr[i];// smaller one
            i++;k++;
        }
    }
    while(i<=mid){// anything left
        b[k]= arr[i];
        i++;k++;
    }
    while(j<=h){
        b[k]= arr[j];
        j++;k++;
    }
    for(int f=0;f<=h;f++){
        arr[f]= b[f];
    }
}

void merge_sort(int arr[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1,h);
        merge(arr, l, mid, h);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int partition_about_1st(int arr[], int low, int high){// return pivot again and again
    int pivot = arr[low];
    int i=low+1,j=high; // as low is already used and we go from high to i in the other in a very good fashion
    while (1)
    {
        while(i<=j && arr[i]<pivot){// jab tak j baad rhega or equal then opposite ho jayega and answer will come
            i++;// basically do nothing
        }
        while(i<=j && arr[j]>pivot){
            j--;// again bas chalne do until i and j meet, if they ever do peeche aane do
        }
        if (j<i) break;
        swap(&arr[i],&arr[j]);// visualize very fun
    }
    swap(&arr[low],&arr[j]);// j chhota wala hai that's why because we have swapped it with i one so it became j,i instead of i,j
    return j;
}

void quick_sort_1st(int arr[], int low, int high){
    // partition then do nothing basically
    if(low<high){
        int pivot= partition_about_1st(arr,low, high);
        quick_sort_1st(arr, low, pivot-1);// split about pivot but not including pivot
        quick_sort_1st(arr, pivot+1, high);
    }
}

int partition_about_last(int arr[], int low, int high){
    int pivot = arr[high];
    int i=low,j=high-1;
    while (1)
    {
        while(i<=j && pivot>arr[i]){
            i++;
        }
        while (i<=j && pivot<arr[j])
        {
            j--;
        }
        if(j<i) break;
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[i],&arr[high]);// swaping the right i to high  good good 
    return j;
}

void quick_sort_about_last(int arr[], int low, int high){
    if(low<high){
        int pivot = partition_about_last(arr, low, high);
        quick_sort_about_last(arr, low, pivot-1);
        quick_sort_about_last(arr, pivot+1, high);
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
    
    // binary_search(arr, n);
    // merge_sort(arr,0,n-1);
    // quick_sort_1st(arr, 0, n-1);
    quick_sort_about_last(arr, 0, n-1);
    display(arr,n);
    return 0;
}
