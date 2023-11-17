#include<stdio.h>
#include<math.h>

int christmas_tree(){
    int n,i=0,j=0;
    printf("How many rows do you want?\n");
    scanf("%d",n);
    for(i=1;i<=n;i++){


    }
    return 0;
}

int copy_christmas(){
   int i, space, rows, k = 0;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i, k = 0) {
      for (space = 1; space <= rows - i; ++space) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("* ");
         ++k;
      }
      printf("\n");
   }
    return 0;
}

int inverted_half_pyramid(){
    int n,i=0,j=0,k,num;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    num=n;
    while(n>=0){
        for (j=0;j<=i;j++)
        {
            printf(" ");
        }
        
        for(k=1;k<=n;k++){
            printf("*");
        }
        printf("\n");
        n--;
        i++;
    }
    return 0;
}


int main(){
    // christmas_tree();
    // copy_christmas();
    // inverted_half_pyramid();
    
    return 0;
}