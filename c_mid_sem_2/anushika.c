// #include<stdio.h>
// int main(){
//     int arr[10],i;
//     for(i=0;i<10;i++){
//         printf("element:%d ",i+1);
//         scanf("%d",&arr[i]);
//     }
//     for(i=0;i<10;i++){
//         printf("%d\t",arr[i]);
//     }
//     return 0;
// }

// #include<stdio.h>
// int main(){
//     int arr[10],arr1[10],i,j;
//     for(i=0;i<10;i++){
//         printf("element:%d ",i+1);
//         scanf("%d",&arr[i]);
//     } 
//     for(j=0;j<10;j++){
//      arr1[j]=arr[j];
//     }

//     for(j=0;j<10;j++) printf("%d",arr1[j]);
// return 0;
// }
#include<stdio.h>
int main(){
int arr[10],arr1[10],i,j,count=0;
     for(i=0;i<10;i++){
      printf("element:%d ",i+1);
      scanf("%d",&arr[i]);
}
for(i=0;i<10;i++){
for(j=0;j<10;j++){
    if(arr[i]==arr[j]&&i!=j){
        count++;
    }
}
}
printf("duplicate number are:%d",count);
return 0;
}