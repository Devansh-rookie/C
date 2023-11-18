#include<stdio.h>

int stairs(int n){
    if(n<=0) return 0;
    else if(n==1||n==2) return n;
    else if(n==3) return 4;
    else return (stairs(n-1)+stairs(n-2)+stairs(n-3));
}



int main(){
    int n;
    scanf("%d",&n);
    printf("%d",stairs(n));
    return 0;
}