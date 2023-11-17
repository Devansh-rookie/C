#include<stdio.h>

int fact(int n){
    int factorial=1;
    for(int i=1;i<=n;i++){
        factorial*=i;
    return factorial;
    }
}

int greater(int x, int y){
    if(x>y) printf("%d(first) is greater than %d(second)",x,y);
    else if(y>x) printf("%d(second) is greater than %d(first)",y,x);
    else printf("Both are the same");
    return 0;
}

void arrays_sum(int arr1[],int arr2[],int n){
    int s1=0,s2=0,i;
    for(i=0;i<n;i++){
        s1+=arr1[i];
    }
    for(i=0;i<n;i++){
        s2+=arr2[i];
    }
    greater(s1,s2);
}

int main(){
    int num;
    // scanf("%d",&num);
    // printf("%d",fact(num));
    int n;
    printf("Size of array\n");
    scanf("%d",&n);
    int arr1[n],arr2[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    arrays_sum(arr1,arr2,n);
    return 0;
}