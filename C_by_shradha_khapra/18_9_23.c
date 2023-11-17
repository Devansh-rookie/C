#include<stdio.h>
#include<math.h>


int pointers_eg1(){
    int i=5;
    int *ptr=&i;
    int **pptr=&ptr;

    printf("%d\n",(*ptr));
    printf("%p\n",(*pptr));// %p is for address
    printf("%d\n",(**pptr));

    return 0;
}



int main(){
    // pointers_eg1();


    return 0;
}