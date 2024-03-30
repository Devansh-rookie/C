#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

int add(int x , int y){
    int carry = (x&y)<<1;
    int add_logic = x^y;
    if(carry==0){
        return add_logic;
    }
    return add(carry, add_logic);
}

// int subtract(int x, int y){
//     while(y!=0){
//         int borrow = (~x)&y;
//         x = x^y;
//         y = borrow<<1;
//     }
//     return x;// after y becomes 0 that is the other number that takes care of the borrows or carries
// }

// int divide(int dividend, int divisor) {
//     bool isDividendNeg=false;
//     bool isDivisorNeg = false;
//     unsigned int valSor, valDend;
//     if(divisor ==1) return dividend;
//     // if(divisor == -1) return -dividend;
//     if(dividend<0){
//         valSor= - dividend;
//         isDividendNeg = true;
//     }
//     else valSor = dividend;
//     if(divisor<0){
//         valDend = - divisor;
//         isDivisorNeg = true;
//     }
//     else valDend = dividend;
//     unsigned int quotient = 0;
//     // this is for positive dividend and divisor
//     while(valDend>= valSor){
//         // dividend = dividend - divisor;
//         valDend = subtract(valDend, valSor);
//         quotient = add(quotient,1);
//     }
//     if(quotient >INT_MAX && isDivisorNeg ^ isDividendNeg){
//         return INT_MIN;
//     }
//     else if(quotient >=INT_MAX && isDivisorNeg ^ isDividendNeg==false){
//         return INT_MAX;
//     }
//     if(isDivisorNeg ^ isDividendNeg) quotient = -quotient;
//     return quotient;
// }

int main(){
    printf("%d", add(1,INT_MIN));
    return 0;
}











// int add(int x , int y){
//     int carry = (x&y)<<1;
//     int add_logic = x^y;
//     if(carry==0){
//         return add_logic;
//     }
//     return add(carry, add_logic);
// }

// int subtract(int x, int y){
//     while(y!=0){
//         int borrow = (~x)&y;
//         x = x^y;
//         y = borrow<<1;
//     }
//     return x;// after y becomes 0 that is the other number that takes care of the borrows or carries
// }

// int divide(int dividend, int divisor) {
//     bool isDividendNeg=false;
//     bool isDivisorNeg = false;

//     if(divisor ==1) return dividend;

//     if(dividend<0){
//         isDividendNeg = true;
//     }
//     if(divisor<0){
//         isDivisorNeg = true;
//     }

//     int quotient = 0;
//     // this is for positive dividend and divisor
//     while(!isDividendNeg && !isDivisorNeg && dividend>= divisor){
//         // dividend = dividend - divisor;
//         dividend = subtract(dividend, divisor);
//         quotient = add(quotient,1);
//     }

//     while(isDivisorNeg && !isDividendNeg && dividend>= -divisor){
//         // dividend = dividend - divisor;
//         dividend = subtract(dividend, -divisor);
//         quotient = add(quotient,1);
//     }

//     while(!isDivisorNeg && isDividendNeg && -dividend>= divisor){
//         // dividend = dividend - divisor;
//         dividend = subtract(divisor, dividend);
//         quotient = add(quotient,1);
//     }

//     while(isDivisorNeg && isDividendNeg && -dividend>= -divisor){
//         // dividend = dividend - divisor;
//         dividend = subtract(dividend, divisor);
//         quotient = add(quotient,1);
//     }

//     if(quotient >INT_MAX && isDivisorNeg ^ isDividendNeg){
//         return INT_MIN;
//     }
//     else if(quotient >=INT_MAX && isDivisorNeg ^ isDividendNeg==false){
//         return INT_MAX;
//     }
//     if(isDivisorNeg ^ isDividendNeg) quotient = -quotient;
//     return quotient;
// }