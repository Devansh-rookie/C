#include<stdio.h>

typedef struct polynomial{
    int expo;
    int coeff;
}poly;

void i_xn_i(){
    int deg;
    printf("What is the degree of the polynomial?: ");
    scanf("%d",&deg);
    int a[deg+1];
    int i=0;
    for(i=0;i<deg+1;i++){
        printf("Coefficient of x^%d: ",deg-i);
        scanf("%d",&a[i]);
    }
    for(int j=0;j<deg;j++){
        if(a[j]<0)
            printf("%dx^%d",a[j],deg-j);
        else if((a[j])>0&&j!=0){
            printf("+%dx^%d",a[j],deg-j);
        }
        else if((a[j])>0&&j==0){
            printf("%dx^%d",a[j],deg-j);
        }
    }
    if (a[deg]>0) printf("+%d",a[deg]);
    else if (a[deg]<0) printf("%d",a[deg]);
}

void i_x_i(){
    int deg;
    printf("What is the degree of the polynomial?: ");
    scanf("%d",&deg);
    int a[deg+1];
    int i=0;
    for(i=0;i<deg+1;i++){
        printf("Coefficient of x^%d: ",i);
        scanf("%d",&a[i]);
    }
    if (a[deg]!=0) printf("%d",a[0]);
    for(int j=1;j<deg+1;j++){
        if(a[j]<0)
            printf("%dx^%d",a[j],j);
        else if((a[j])>0&&j!=0){
            printf("+%dx^%d",a[j],j);
        }
        else if((a[j])>0&&j==0){
            printf("%dx^%d",a[j],j);
        }
    }
}

void _2d_arr(){
    int degree;
    printf("What is the degree of the polynomial?: ");
    scanf("%d",&degree);
    int a[degree+1][2];
    for(int i=0;i<degree+1;i++){
        printf("Coefficient of x^%d: ",i);
        scanf("%d",&a[i][0]);
        a[i][1]=i;
    }
    if (a[degree][0]!=0) printf("%d",a[0][0]);
    for(int j=1;j<degree+1;j++){
        if(a[j][0]<0)
            printf("%dx^%d",a[j][0],a[j][1]);
        else if((a[j][0])>0&&j!=0){
            printf("+%dx^%d",a[j][0],a[j][1]);
        }
        else if((a[j][0])>0&&j==0){
            printf("%dx^%d",a[j][0],a[j][1]);
        }
    }
    
}

void arr_str(){
    int degree;
    printf("What is the degree of the polynomial?: ");
    scanf("%d",&degree);
    poly a[degree+1];
    for(int i=0;i<degree+1;i++){
        printf("Coefficient of x^%d: ",i);
        scanf("%d",&a[i].coeff);
        a[i].expo=i;
    }
    if (a[degree].coeff!=0) printf("%d",a[0].coeff);
    for(int j=1;j<degree+1;j++){
        if(a[j].coeff<0)
            printf("%dx^%d",a[j].coeff,a[j].expo);
        else if((a[j].coeff)>0&&j!=0){
            printf("+%dx^%d",a[j].coeff,a[j].expo);
        }
        else if((a[j].coeff)>0&&j==0){
            printf("%dx^%d",a[j].coeff,a[j].expo);
        }
    }
}

int main(){
    // i_xn_i();
    // i_x_i();
    // _2d_arr();
    // arr_str();
    return 0;
}

