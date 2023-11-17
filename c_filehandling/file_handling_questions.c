#include<stdio.h>

void write_prime_numbers(){
    int i,n,flag;
    scanf("%d",&n);
    FILE *fptr;
    fptr= fopen("prime_numbers.txt", "w");
    for(i=2;i<n;i++){
        flag=0;
        for(int j=2;j<i/2+1;j++){
            if(i%j==0) flag =1;
        }
        if(!flag) fprintf(fptr, "%d\n", i);
    }
    fclose(fptr);
}

int main(){
    write_prime_numbers();
    return 0;
}

