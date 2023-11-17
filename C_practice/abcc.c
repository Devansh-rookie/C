#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 45, 67, 56, 74};
    int i = 4, *j, *k, *m, *n;
    j = &i;
    j = j + 9; //
    k = &i;
    k = k - 3;
    m = &arr[1];
    n = &arr[5];
    int a=n-m;
    printf("%d\n %d %d ", a ,n,m);
    j = &arr[4];

    k = (arr + 4);
    if (j == k)
    {
        printf("code id right");
    }
    else
        printf("wrong");

    return 0;
}