// using recursion fibonacci series fib n-1 and fib n-2 
// Sum of n natural numbers using recursion
// Digit Sum using recursion
// x,y swap function using pointers.
// arr input then sort function then return the array
// tower of hanoi
#include<stdio.h>

int fib(int n){
    if(n==1) return 0;
    else if(n==2) return 1;
    else return (fib(n-1)+fib(n-2));
}

int sum(int n){
    if(n==1) return 1;
    else return (n+sum(n-1));
}

int digit_sum(int n){
    if(n==0) return 0;
    return (digit_sum(n/10)+n%10);// use n%10 here then reduce to n/10 there
}

void swap(int *x,int *y){
    int temp = *x;// we will take temp as integer then use dereferening in x and y
    *x=*y;
    *y=temp;
}

int *sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[i]) swap(&arr[j],&arr[i]);
        }
    }
    return arr;
}

int main(){
    // int n;
    // scanf("%d",&n);
    // for(int i=1;i<=n;i++) printf("%d ",fib(i));

    // int n;
    // scanf("%d",&n);
    // printf("%d",sum(n));

    // int n;
    // scanf("%d",&n);
    // printf("%d",digit_sum(n));

    // int a,b;
    // scanf("%d %d",&a,&b);
    // swap(&a,&b);
    // printf("%d %d",a,b);

    // int n;
    // scanf("%d",&n);
    // int arr[n];
    // int *p;
    
    // for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    // p= sort(arr,n);
    // for(int i=0;i<n;i++){
    //     printf("%d ",*p);
    //     p++;
    // }
}
