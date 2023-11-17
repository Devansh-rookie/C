#include <stdio.h>

int diamond()
{
    return 0;
}

// int main(){
//     diamond();

//     int n,i,j,space,k;
//     printf("Rows:\n");
//     scanf("%d",&n);

//     for ( i = 1; i <= 2*n-1; i++)
//     {
//         if(i<=n){
//         for ( j = 1; j <= n-i; j++)
//         {
//             printf(" ");
//         }
//         for ( k = 1; k<=2*i-1; k++)
//         {
//             printf("*");
//         }
//         printf("\n");
//         }
//         else{
//         for(j=1;j<=i-n;j++){
//             printf(" ");
//         }
//         for(k=2*(2*n-i)-1;k>0;k--){
//             printf("*");
//         }
//         printf("\n");
//         }

//     }

//     return 0;
// }

// int main()
// {
//     int n, i, j, k;
//     printf("Rows:\n");
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++)
//     {
//         for (j = 1; j <= n - i; j++)
//         {
//             printf(" ");
//         }
//         for (k = 1; k <= 2 * i - 1; k++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     for (i = 1; i <= n - 1; i++)
//     {
//         for (j = 1; j <= i; j++)
//         {
//             printf(" ");
//         }
//         for (k = 2 * (n - i); k > 1; k--)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
//     return 0;
// }

// int main(){
//     int n,i,j=1;
//     printf("Rows:\n");
//     scanf("%d", &n);
//     for(i=1;i<=2*n-1;i++){
//         printf("%c",(char)i+64);
//     }
//     printf("\n");
//     for(i=1;i<=(n-1);i++){
//         for(j=1;j<=n-i;j++){
//             printf("%c",(char)j+64);
//         }
//         for(j=1;j<=2*i-1;j++){
//             printf(" ");
//         }
//         for(j=1;j<=n-i;j++){
//             printf("%c", (char)j+n+i-1+64);
//         }
//         printf("\n");       
        
//     }
//     return 0;
// }


// int main(){
//     int n,i,j=1;
//     printf("Rows:\n");
//     scanf("%d", &n);
//     for(i=1;i<=n;i++){
//         printf("%d",i);
//     }
//     for(i=n-1;i>=1;i--){
//         printf("%d",i);
//     }

//     printf("\n");
//     for(i=1;i<=(n-1);i++){
//         for(j=1;j<=n-i;j++){
//             printf("%d",j);
//         }
//         for(j=1;j<=2*i-1;j++){
//             printf(" ");
//         }
//         for(j=n-i;j>=1;j--){
//             printf("%d", j);
//         }
//         printf("\n");       
        
//     }
//     return 0;
// }

int main(){
    int n=100,i,j,flag;
    for(i=2;i<=n;i++){
        flag=0;
        for ( j = 2; j<=i/2+1; j++)
        {
            if(i%j==0){
                flag =1;
            }

        }
        if(flag==0){
            printf("%d\n",i);
        }
        
    }
    return 0;
}