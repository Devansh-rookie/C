#include<stdio.h>
#include<time.h>
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
    int n;
    // time_t start = time(NULL); This would include the time taken for the user to enter the values
    printf("What is the length of the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    time_t start = time(NULL);
    merge_sort(arr,0,n-1);
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
    printf("\n");
    time_t end = time(NULL);
    printf("Time taken to run the program: %lf seconds.", difftime(end,start));
    return 0;
}
