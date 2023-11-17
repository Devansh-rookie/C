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
    int arr[100],count=0;
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(i!=j&& arr[i]==arr[j]){
                count++;
                for(int k=i;k<n;k++) arr[k]=arr[k+1];
                n--;
                j=0;
            }
        }
        if(arr[i]==0) printf("Total number of %d is: %d\n",arr[n],count+1);
        else printf("Total number of %d is: %d\n",arr[i],count+1);
    }
}

void swap(int *x,int *y){
    int temp = *x;// we will take temp as integer then use dereferening in x and y
    *x=*y;
    *y=temp;
}

void insertion_ati(){
    int i,l,n,key;
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    printf("Where to insert and what to insert?\n");
    scanf("%d %d",&l,&key);
    for(i=0;i<n+1;i++){
        if(i==l){
            for(int k=n;k>=i;k--) arr[k+1]=arr[k];
            arr[l]=key;
        }
    }
    for(int i=0;i<n+1;i++) printf("%d ",arr[i]);
}


void add_two(){
    int x,y,sum;
    scanf("%d %d",&x,&y);
    int *p1=&x;
    int *p2=&y;
    sum = *p1+ *p2;
    printf("%d",sum);
}

void pointers_arr(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    for(int i=0;i<n;i++) printf("%d\t",*(arr+i));
}

// void runner_code(){
//     int n;
//     int fact=1;
//     scanf("%d",&n);
//     pointer_factorial(n,&fact);
//     printf("%d",fact);
// }

// void pointer_factorial(int n, int *fact){
//     *fact=1;
//     for(int i=1;i<=n;i++) *fact=*fact*i;
//     printf("%d",*fact);
// }

void bubble_sort(){
    int n;
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]>arr[i]){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d\t",arr[i]);
}

void binary_search(){
    int s,l,mid,n;
    int key;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    s=0;
    l=n-1;
    scanf("%d",&key);
    mid= (s+l)/2;
    while(s<=l){
        
        if(arr[mid]==key){
            printf("Key found at %d",mid);
            break;
        }
        else if(arr[mid]<key){
            s= mid+1;
        }
        else{
            l= mid-1;
        }
        mid= (s+l)/2;
    }
}

int main(){
    binary_search();
    // bubble_sort();
    // matrix_add();
    // matrix_mul();
    // sparce_matrix();
    // determinant();
    // duplicate();
    // insertion_ati();
    // add_two();
    // pointers_arr();
    // runner_code();
}
