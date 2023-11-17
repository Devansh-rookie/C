#include <stdio.h>
#include<math.h>
int main()
{
  int i, j, n = 6;
  for (i=0; i<n; i++)
  {
    for (j=n-i; j>1; j--)
    {
      printf(" ");
    }
    for (j=0; j<=i; j++ )
    {
      printf("* ");
    }
    // Move the cursor to new line for next row
    printf("\n");
  }
  return 0;
}

// int pyramid(){

//     return 0;
// }

// int main(){

//     return 0;
// }
