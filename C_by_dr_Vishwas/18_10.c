#include<stdio.h>

void matrix_multiplication(){
    int i,j,k,r1,r2,c1,c2;
    int m1[r1][c1],m2[r2][c2],m3[r1][c2];
    printf("What is r1 c1 r2 c2?\n");
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            m3[i][j]=0;
        }
    }
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&m1[i][j]);
        }
    }
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&m2[i][j]);
        }
    }
    if(r2==c1){
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            for(k=0;k<r2;k++){
                m3[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",m3[i][j]);
        }
        printf("\n");
    }
}
else printf("Matrix not compatible.\n");
}

void max_sum(){
    int n,i,max=0,streak=0,temp=0,positive_negative=0;
    printf("Length of array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
// add condition if all positive then postive_neg =1 and other is -1
    for(i=0;i<n;i++){
        if (arr[i]>=0){ 
            max=max+arr[i];
        }
        else if(arr[i]<0&&max>temp){
            temp=max;
            max=0;
        }
        else max=0;
    }
    if(max>temp) temp=max;
    printf("Max: %d",temp);
}

void sum_all_pairs(){
    // sorted array non repeated values
    int n,i,num,sum,j;
    printf("Length of array: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("What is the number to check: ");
    scanf("%d",&num);




}

int recursion(int n){
    int i;
    for(i=0;i<n;i++){
        recursion(n);
    }
}
    

int main(){
    // matrix_multiplication();
    // max_sum();
    sum_all_pairs();
    return 0;
}