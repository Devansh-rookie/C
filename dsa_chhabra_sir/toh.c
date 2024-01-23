#include<stdio.h>
void toh(int n, char s,char a, char d){
    if(n==1){
        printf("Disk %d from %c to %c\n",n,s,d);
    }
    else{
        toh(n-1,s,d,a);
        printf("Disk %d from %c to %c\n",n,s,d);
        toh(n-1,a,s,d);
    }
}

int main(){
    int n;
    printf("Tell the number of disks: ");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}



