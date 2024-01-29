#include<stdio.h>


// when both the elements are sorted
void merge(int a[],int b[],int n,int m){
    int i=0,j=0,k=0;
    int c[n+m];
    while(i<n&& j<m){
        if(a[i]>=b[j]){
            c[k]=b[j];
            j++;
            k++;
        }
        else{
            c[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<n){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<m){
        c[k]=b[j];
        j++;
        k++;
    }
    for(int h=0;h<m+n;h++){
        printf("%d ", c[h]);
    }
}

void merge_in_same_arr(int a[],int l,int mid, int h){
    int i,j,k;
    i=l;j=mid+1;k=l;
    int b[100];
    while(i<=mid&&j<=h){
        if(a[i]>=a[j]){
            b[k]=a[j];
            j++;
            k++;
        }
        else{
            b[k]=a[i];
            i++;
            k++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        k++;i++;
    }
    while(j<=h){
        b[k]=a[j];
        k++;j++;
    }
    for(int c=l;c<=h;c++){
        a[c]=b[c];
    }
    // for(int c=0;c<h-l+1;c++){
    //     printf("%d ", a[c]);
    // }
}

void iterative_merge_sort(int a[], int n){
    int p,i,j,l,h,mid;
    for(p=2;p<=n;p=p*2){
        for(i=0;i+p-1<=n;i=i+p){// i+p-1 that is the previous h should be less than equal n
            l=i;
            h=p+i-1;
            mid=(l+h)/2;
            merge_in_same_arr(a,l,mid,h);
        }
    }
    if (p/2<n)
        {
            merge_in_same_arr(a,0,p/2-1,n);
    }
}

void display(int arr[],int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

int main(){
    // int a[]= {2, 10 ,25, 18,20 ,23};
    // int b[]= {4,9,19,25};
    // // merge(a,b,5,4);
    // printf("\n");
    // int c[]={2,5,8,12,3,6,7,10};
    // merge_in_same_arr(a,0,2,5); 
    // display(a,6);
    int A[]={34,12,25,1,5,3,7,8,10,1,4,3,5};
    iterative_merge_sort(A,13);
    display(A,13);
    return 0;
}
