#include<stdio.h>

int main(){
    int n,s1,s2,s3;
    scanf("%d",&n);
    s1=0;
    s2=1;
    printf("%d %d ",s1,s2);
    for(int i=1;i<n-1;i++){
        printf("%d ",s1+s2);
        s3=s2;
        s2=s1+s2;
        s1=s3;
    }

    return 0;
}

