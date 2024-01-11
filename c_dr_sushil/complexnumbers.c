#include<stdio.h>

typedef struct complex_number{
    float real;
    float imag;
}complex;


complex addition(complex c1, complex c2, complex result){
    (result).real= c1.real+c2.real;
    (result).imag= c1.imag+c2.imag;
    return result;
}

complex subtraction(complex c1, complex c2, complex result){
    (result).real= c1.real-c2.real;
    (result).imag= c1.imag-c2.imag;
    return result;
}

complex multiplication(complex c1, complex c2, complex result){
    (result).real= c1.real*c2.real-c1.imag*c2.imag;
    (result).imag= c1.imag*c2.real+c1.real*c2.imag;
    return result;
}

int main(){
    complex result,r;
    complex c1,c2;

    scanf("%f %f",&c1.real,&c1.imag);
    scanf("%f %f",&c2.real,&c2.imag);

    r= multiplication(c1,c2,result);

    printf("%0.2f +i(%0.2f)",r.real,r.imag);
    return 0;
}