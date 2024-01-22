#include<stdio.h>
#include<math.h>
int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int abs(int a){// abs absolute
    if(a>0) return a;
    else return -a;
}

int *poly_add(int poly1[],int poly1_deg ,int poly2[],int poly2_deg){
    int k=max(poly1_deg,poly2_deg);
    int f = abs(poly1_deg-poly2_deg);// or we can make abs by if statements
    int result[k+1];
    for(int i=k;i>=0&&poly1_deg>=poly2_deg;i--){
        if(i>=f){
            result[i]=poly1[i]+poly2[i-f];
        }
        else{
            result[i]=poly1[i];
        }
    }
    for(int i=k;i>=0&&poly1_deg<poly2_deg;i--){
        if(i>=f){
            result[i]=poly1[i-f]+poly2[i];
        }
        else{
            result[i]=poly2[i];
        }
    }
    printf("%d",result[k]);
    for(int i=k-1;i>=0;i--){
        printf("+(%dx^%d)",result[i],k-i);
    }
    return result;
}

int main(){
    int deg1,deg2;
    scanf("%d %d",&deg1,&deg2);
    int poly1[deg1+1],poly2[deg2+1];
    for(int i=deg1;i>=0;i--){
        printf("Coefficient of Polynomial 1: %d: ",deg1-i);
        scanf("%d",&poly1[i]);
    }
    for(int i=deg2;i>=0;i--){
        printf("Coefficient of Polynomial 2: %d: ",deg2-i);
        scanf("%d",&poly2[i]);
    }
    poly_add(poly1,deg1,poly2,deg2);
    return 0;
}
