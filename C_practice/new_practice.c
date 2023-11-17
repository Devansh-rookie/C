#include<stdio.h>

void matrix_add(){
    int n;
    scanf("%d",&n);
    int arr1[n][n],arr2[n][n],arr3[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&arr1[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&arr2[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) arr3[i][j]=arr1[i][j]+arr2[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d\t",arr3[i][j]);
        printf("\n");
    }
}

void matrix_mul(){
    int n;
    scanf("%d",&n);
    int arr1[n][n],arr2[n][n],arr3[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&arr1[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&arr2[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) arr3[i][j]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++) arr3[i][j]+=arr1[i][k]*arr2[k][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d\t",arr3[i][j]);
        printf("\n");
    }

}

void sparce_matrix(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr1[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) scanf("%d",&arr1[i][j]);
    }
    int count_0=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) if(arr1[i][j]==0) count_0++;
    }
    int number_elements =n*m;
    if (count_0>number_elements/2){
        printf("Sparce Matrix");
    }
}

void determinant(){
    int arr[3][3],det=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++) scanf("%d",&arr[i][j]);
    }
    det= arr[0][0]*(arr[1][1]*arr[2][2]-arr[2][1]*arr[1][2])-arr[0][1]*(arr[1][0]*arr[2][2]-arr[2][0]*arr[1][2])+arr[0][2]*(arr[1][0]*arr[2][1]-arr[2][0]*arr[1][1]);
    
    printf("%d",det);
}

void duplicate(){
    int n,i;
    scanf("%d",&n);
    int arr[n],arr1[n],count=0;
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    for(i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(i!=j&& arr[i]==arr[j]){
                count++;
                for(int k=i;k<n;k++) arr[k]=arr[k+1];
                n--;
            }
        }
        printf("Total number of %d is: %d\n",arr[i],count+1);
    }
}

int main(){
    // matrix_add();
    // matrix_mul();
    // sparce_matrix();
    // determinant();
    duplicate();
}
