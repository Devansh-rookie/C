#include<stdio.h>

void call_address_reference(int *a,int* b){
    int temp = *a;
    *a=*b;
    *b=temp;
    printf("Inside values of a: %d and b: %d\n",*a,*b);
}

void call_value(int a, int b){
    int temp = a;
    a=b;
    b=temp;
    printf("Inside values of a: %d and b: %d\n",a,b);
}

// void call_reference(int &a,int &b){
//     int temp = a;
//     a=b;
//     b=temp;
//     printf("Inside values of a: %d and b: %d\n",a,b);
// }

typedef struct complex{
    float real;
    float imag;
}complex;
// static complex *result;(*p=&a)
complex *addition(complex *c1, complex *c2){
    complex a;
    complex *result=&a;// the error was coming as result was not defined now its defined at a
    result->real = c1->real+c2->real;
    result->imag = (*c1).imag +(*c2).imag; // *c1.imag will not work because it will consider the entire thing as an pointer and find its address brackets will make it confined to c1 or c2 
    return result;
}

complex addition_nop(complex *c1, complex *c2){
    complex result;
    result.real = c1->real+c2->real;
    result.imag = (*c1).imag +(*c2).imag; // *c1.imag will not work because it will consider the entire thing as an pointer and find its address brackets will make it confined to c1 or c2 
    return result;
}


int main(){
    // int a=10;
    // int b=15;
    // call_value(a,b);
    // printf("In main a: %d b: %d\n",a,b);
    // call_address_reference(&a,&b);
    // printf("In main a: %d b: %d\n",a,b);
    // call_reference(&a,&b);
    // printf("In main a: %d b: %d\n",a,b);

    // deep copy and shallow copy

    complex c1,c2;
    scanf("%f %f",&c1.real,&c1.imag);
    scanf("%f %f",&c2.real,&c2.imag);
    // complex *c1p=&c1;
    // complex *c2p=&c2;
    // complex r= addition_nop(&c1,&c2);
    // printf("%f + i(%f)",r.real,r.imag);
    complex *r = addition(&c1,&c2);
    printf("%f + i(%f)",r->real,r->imag);
    return 0;
}