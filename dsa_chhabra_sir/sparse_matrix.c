#include<stdio.h>
typedef struct sparse
{
    int row,col,value;
}sparse;

void sparse_disp(sparse arr[],int n);

// sparse *mat_scan(sparse arr[],int n){
//     printf("What are the numbers of Rows and Columns: ");
//     scanf("%d %d",&arr[0].row,&arr[0].col);
//     printf("Enter non-zero values:\n");
//     for(int i=1;i<n+1;i++){
//         printf("Row Column Value");
//         scanf("%d %d %d",&arr[1].row,&arr[1].col,&arr[1].value);
//     }
//     return arr;
// }


void display(sparse arr[],int n){
    printf("\n");
    int c=1;
    for (int i = 0; i < arr[0].row; i++)
    {
        for (int j = 0; j < arr[0].col; j++)
        {
            if (arr[c].row==i&&arr[c].col==j)
            {
                printf("%d\t",arr[c].value);
                c++;
            }
            else printf("0\t");
        }
        printf("\n");
    }
}


void transpose_selftry(sparse arr[],int n){
    for(int i=0;i<n+1;i++){
        int temp = arr[i].row;
        arr[i].row= arr[i].col;
        arr[i].col=temp;
    }
    display(arr,n);
}

void swap(int *a,int *b){
    int *temp = a;
    a=b;
    b=temp;
}



void transpose_after_hint(sparse arr[],int n){

    // check column numbers and store them into the new matrix in an increasing order so as to make the displaying easier
    sparse new[n+1];
    int c=1;
    new[0].col=arr[0].row;
    new[0].row=arr[0].col;
    for(int i=0;i<arr[0].col;i++){// check all the columns from 0 to max
        for (int j = 1; j < n+1; j++)
        {
            if (arr[j].col==i)
            {
                new[c].col=arr[j].row;
                new[c].row=arr[j].col;
                new[c].value=arr[j].value;
                c++;
            }
        }
        
    }
    display(new,n);
    sparse_disp(new,n);
}

// the function has to be declared above if it is to be executed like that

void sparse_disp(sparse arr[], int n){
    printf("\n");
    for(int i=0;i<n+1;i++){
        printf("%d %d %d\n",arr[i].row,arr[i].col,arr[i].value);
    }
}

int main(){
    int n;
    printf("How many non-zero values to be stored: ");
    scanf("%d",&n);
    sparse arr[n+1];

    printf("What are the numbers of Rows and Columns: ");
    scanf("%d %d",&arr[0].row,&arr[0].col);
    printf("Enter non-zero values:\n");
    for(int i=1;i<n+1;i++){
        printf("Row Column Value\n");
        scanf("%d %d %d",&arr[i].row,&arr[i].col,&arr[i].value);
    }
    display(arr,n);
    transpose_after_hint(arr,n);
    return 0;
}
