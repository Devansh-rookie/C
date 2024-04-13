#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>


void sum(){
    long long int a;
    scanf("%lld",&a);
    long long int sum_bt=1;
    while(a!=1){
        sum_bt+=a;
        a = a/2;
    }
    printf("%lld\n",sum_bt);
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        sum();
    }
    return 0;
}