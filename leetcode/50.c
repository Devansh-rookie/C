#include<math.h>
double myPow(double x, int n) {
    if(x==0) return 0.0;
    else if(n==0||x==1) return 1.0;
    double a= myPow(x,n/2);
    if(n%2==0){
        return a*a;
    }
    else{
        if(n>0) return x*a*a;
        else return (a*a)/x;
    }
}