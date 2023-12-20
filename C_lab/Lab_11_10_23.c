#include<stdio.h>

void odd_even(){
    int n,i,c_o=0,c_e=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]%2==0){
            c_e++;
        }
        else c_o++;
    }
    printf("Even: %d\nOdd: %d",c_e,c_o);
}

void sum_avg(){
    int n,i,sum=0;
    float avg=0.0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    avg=(float)sum/n;
    printf("%f %d",avg,sum);
}

void search_index(){
    int i,n,key,flag=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("What element do you want to search?\n");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(arr[i]==key){
            printf("%d found at %d",key,i);
            flag=1;
            break;
        }
    }
    if(flag!=0) printf("Key %d not found in the array.",key);
}

void max_second_max(){
    int i,n,max,max2;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    for(i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    max2=-max;
    for(i=0;i<n;i++){
        if(arr[i]>max2){
            if(max>arr[i]) {//Note to self:Important* repeated mistake
                max2=arr[i];
                }
        }
    }
    printf("Max is: %d\nSecond Max is: %d",max,max2);
}

void add_element(){
    int i,n,key,value;
    printf("How many digits do you want to enter? ");
    scanf("%d",&n);
    int arr[100];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("What and where(index) to add?\n");
    scanf("%d %d",&value,&key);
    for(i=n;i>=key;i--){
        arr[i+1]=arr[i];
    }
    arr[key]=value;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void delete_element(){
    int i,n,key;
    printf("How many digits do you want to enter? ");
    scanf("%d",&n);
    int arr[100];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("From where(index) to delete?\n");
    scanf("%d",&key);
    for(i=key;i<n;i++){
        arr[i]=arr[i+1];
    }
    for(i=0;i<n-1;i++){
        printf("%d ",arr[i]);
    }
}

void delete_element_value_distinct(){
    int i,n,value,key,flag=0;
    printf("How many digits do you want to enter? ");
    scanf("%d",&n);
    int arr[100];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("What to delete?\n");
    scanf("%d",&value);
    for(i=0;i<n;i++){
        if(arr[i]==value){
            flag=1;
            key=i;
            break;
        }
    }
    if(flag==1){
        for(i=key;i<n;i++){
            arr[i]=arr[i+1];
        }
        for(i=0;i<n-1;i++){
            printf("%d ",arr[i]);
        }
    }
    else{
        printf("Element not found in the array.");
    }
}

void delete_element_value_repeated(){
    int i,n,value,key,flag=0,count=0,j,k;
    printf("How many digits do you want to enter? ");
    scanf("%d",&n);
    int arr[100];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("What to delete?\n");
    scanf("%d",&value);
    for(i=0;i<n;i++){
        for(k=0;k<n;k++){
        if(arr[k]==value){
            flag=1;
            key=k;
            for(j=key;j<n;j++){
                arr[j]=arr[j+1];
            }
            count++;
        }
        }
    }
    if(flag==1){
        for(i=0;i<n-count;i++){
            printf("%d ",arr[i]);
            }
    }
    else{
        printf("Element not found in the array.");
    }
}

void new_array(){
    int n,i,j,k,count=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int arr2[n];
    for(i=0;i<n;i++){
        arr2[i]=arr[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-count;j++){//j<n-count
            if(i!=j&&arr[i]==arr[j]){
                for(k=j;k<n;k++){
                    arr[k]=arr[k+1];
                }
                count++;
            }
        }
    }
    for(i=0;i<n-count;i++){
        printf("%d ",arr[i]);
    }
}

void sorting_kth(){
    int n,kth,i,j;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("What is K: ");
    scanf("%d",&kth);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("The Kth largest is %d",arr[n-kth+1]);

}

int stairs(int n){
    if(n==1) return 1;
    else return (stairs(n-2)+stairs(n-1));
}



int main(){
    // odd_even();
    // sum_avg();
    // search_index();
    // max_second_max();
    // add_element();//option + question mark = ÷
    // delete_element();
    // delete_element_value_distinct();
    // delete_element_value_repeated();
    // new_array();
    // sorting_kth();
    return 0;
}
