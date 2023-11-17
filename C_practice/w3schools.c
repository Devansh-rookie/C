//https://www.w3resource.com/c-programming-exercises/array/index.php
#include<stdio.h>
#include<math.h>

int q7_merge_desc(){
    int n,i,temp,j;
    int arr[n],arr2[n];

    printf("What are the number of values in arrays?\n");
    scanf("%d",&n);
    printf("For First Array:\n");
    for(i=0;i<n;i++){
        printf("What is value of number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Now for second array:\n");
    for(i=0;i<n;i++){
        printf("What is value of number %d: ",i+1);
        scanf("%d",&arr2[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j>=i){
            if(arr[i]<arr[j]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j>=i){
            if(arr2[i]<arr2[j]){
                temp=arr2[j];
                arr2[j]=arr2[i];
                arr2[i]=temp;
            }
            }
        }
    }

    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
        printf("%d\t",arr2[i]);
    }

    
    return 0;
}


int q8_count_frequency(){
    int n,i,j,count=0;
    int arr[n];
    printf("What are the number of values?: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("What is value number %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        printf("%d occurs %d times.\n",arr[i], count);
    }

    return 0;
}

int q9_(){
    
    return 0;
}

int main(){
    // q7_merge_desc();
    // q8_count_frequency();

    return 0;
}

