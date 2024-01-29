#include<stdio.h>

typedef struct poly// this poly can also be skipped
{
    int exp,coeff;
}poly;
// assume that the values are entered in decreasing order
void poly_add(poly p1[],poly p2[],int n1,int n2){
    int i=0, j=0,k=0;
    poly p3[50];
    for(i=0,j=0;i< n1 && j<n2;){
        if(p1[i].exp==p2[j].exp){
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].exp=p1[i].exp;
            k++;i++;j++; // this can also be done
        }
        else if(p1[i].exp>p2[j].exp){
            p3[k]=p1[i];
            i++;k++;
        }
        else{
            p3[k]=p2[j];
            j++;k++;
        }
    }
    i=0;
    while(i<n1){
        if(p1[i].exp>p2[j].exp){
            p3[k]=p1[i];
            i++;k++;
        }
    }
    j=0;
    while(i<n2){
        if(p1[i].exp<p2[j].exp){
            p3[k]=p2[j];
            j++;k++;
        }
    }
    for (int a = 0; a < k; a++)
    {
        printf("%dx^%d+",p3[a].coeff,p3[a].exp);
    }
    
}

int main(){
    int n1,n2;
    printf("What are the number of terms in Poly 1: ");
    scanf("%d",&n1);
    printf("What are the number of terms in Poly 2: ");
    scanf("%d",&n2);

    poly p1[n1], p2[n2];
    printf("Polynomial 1:\n");
    for (int i = 0; i < n1; i++)
    {
        printf("What is the exponent: ");
        scanf("%d",&p1[i].exp);
        printf("What is the coefficient: ");
        scanf("%d",&p1[i].coeff);
    }
    printf("Polynomial 2:\n");
    for (int i = 0; i < n2; i++)
    {
        printf("What is the exponent: ");
        scanf("%d",&p2[i].exp);
        printf("What is the coefficient: ");
        scanf("%d",&p2[i].coeff);
    }

    poly_add(p1,p2,n1,n2);

    return 0;
}
