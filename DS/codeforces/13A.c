#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

int * returnSumTerms(int num, int base){// won't work for base > greater than sum
    int* arr = (int*)malloc(sizeof(int)*2);
    // arr[0] for sum and arr[1] for no of terms
    arr[0]=0;arr[1]=0;
    if(base>num){
        arr[0]+= num;
        arr[1]++;
        return arr;
    }
    while (num!=0 && num>=base)
    {
        arr[0]+= num%base;
        arr[1]++;
        num= num/base;
    }
    arr[0]+= num;
    return arr;
}

int * makeCoPrime(int a, int b){
    int* arr = (int*)malloc(sizeof(int)*2);
    arr[0]=a;arr[1]=b;

    for(int i=2;i<b+1;i++){
        if(a%i==0 && b%i==0){
            arr[0]= a/i;
            arr[1]= b/i;
        }
    }
    return arr;
}

int main(){
    // printf("%d", returnSumTerms(1,4)[1]);
    int n;
    int sum =0;
    scanf("%d", &n);
    for(int i=2;i<n;i++){
        sum += returnSumTerms(n,i)[0];
    }
    int *arr = makeCoPrime(sum, n-2);
    printf("%d/%d", arr[0],arr[1]);
    return 0;
}
