#include<stdio.h>

typedef struct poly
{
    int exp;int coeff;
} poly;

// store degree int exp of 0 and the coeff store the number of terms in the 0th index

int search_index(int key, poly p[],int k){
    for(int i=1; i<= k;i++){
        if(p[i].exp==key) return i;
    }
    return -1;
}

void poly_mul(poly p1[], poly p2[]){
    poly p3[p1[0].coeff*p2[0].coeff];
    int i=0;int k=0;int j=0;
    for(int i=1;i<=p1[0].coeff*p2[0].coeff;i++){
        p3[i].coeff=0;
        p3[i].exp=0;
    }
    for(int i=1;i<= p1[0].coeff;i++){
        for(int j=1;j<= p2[0].coeff;j++){
            if(search_index(p1[i].exp+p2[j].exp,p3,k)==-1){
                p3[k].exp= p1[i].exp+p2[j].exp;
                p3[k].coeff= p1[i].coeff*p2[j].coeff;
                k++;
            }
            else{
                int index = search_index(p1[i].exp+p2[j].exp,p3,k);
                p3[index].coeff += p1[i].coeff*p2[j].coeff;
            }
        }
    }
    for (int a = 1; a <=k; a++)
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

    poly p1[n1+1], p2[n2+1];
    p1[0].coeff=n1;p2[0].coeff=n2;
    printf("Polynomial 1:\n");
    for (int i = 1; i <= n1; i++)
    {
        printf("What is the exponent: ");
        scanf("%d",&p1[i].exp);
        printf("What is the coefficient: ");
        scanf("%d",&p1[i].coeff);
    }
    printf("Polynomial 2:\n");
    for (int i = 1; i <=n2; i++)
    {
        printf("What is the exponent: ");
        scanf("%d",&p2[i].exp);
        printf("What is the coefficient: ");
        scanf("%d",&p2[i].coeff);
    }
    poly_mul(p1,p2);
    return 0;
}
