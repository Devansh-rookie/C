// #include<stdio.h>

// int prime_factors(int n){
//     if(n==1) return 1;
//     else return n;
// }

// #include<stdio.h>

// int prime_factor(int n){
//     for(int i=2;i<=n;i++){
//         if(n%i==0){
//             printf("%d ",i);
//             return prime_factor(n/i);
//         }
//     }
    
// }

// int main(){
//     int n,i=2;
//     scanf("%d",&n);
//     // for(i=2;i<=n;i++){
//     //     while(n%i==0){
//     //         n=n/i;
//     //         printf("%d ",i);
//     //     }
//     // }
//     prime_factor(n);
// }

#include<stdio.h>

static int i=0;

int print_elem(int arr[], int n){
    if(i<n){
        printf("%d\n",arr[i]);
        i++;
        print_elem(arr, n);
    }
    else return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    print_elem(arr,n);
    return 0;
}
