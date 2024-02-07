#include<stdio.h>

typedef struct poly
{
    int exp;
    int coeff;
}poly;

void display(poly p[],int n){
    for(int i=0;i<n;i++){
        if (p[i].coeff>0) printf(" +%d x^%d ",p[i].coeff,p[i].exp);
        else if(p[i].coeff<0) printf(" %d x^%d ",p[i].coeff,p[i].exp);
    }
}

void sort_expo(poly p[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].exp<p[j+1].exp){// Change the sign from '<' to '>' to make it ascending 
                poly temp = p[j];
                p[j]= p[j+1];
                p[j+1]= temp;
            }
        }
    }
}

int search_index(int expo, poly p[], int n){
    for(int i=0;i<n;i++){
        if(p[i].exp==expo) return i;
    }
    return -1;
}

void poly_mul(poly p1[], poly p2[],int m,int n){
    poly result[m*n];
    int k=0;
    for(int i=0;i<m*n;i++){
        result[i].coeff=0;
        result[i].exp=0;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(search_index(p1[i].exp+p2[j].exp,result,k)==-1){
                result[k].exp= p1[i].exp+p2[j].exp;
                result[k].coeff= p1[i].coeff*p2[j].coeff;
                k++;
            }
            else{
                int index = search_index(p1[i].exp+p2[j].exp,result,k);
                result[index].coeff+= p1[i].coeff*p2[j].coeff;
            }
        }
    }
    sort_expo(result,k);
    display(result,k);
}

void input(poly p[], int n){
    for(int i=0;i<n;i++){
        printf("Exponent and Coefficient of the Term %d:\n",i+1);
        scanf("%d %d", &p[i].exp,&p[i].coeff);
    }
}

int main(){
    int m,n;
    printf("Give the number of terms in Polynomial 1 and Polynomial 2: \n");
    scanf("%d %d",&m,&n);
    poly p1[m];
    poly p2[n];
    printf("Give input for Polynomial 1:\n");
    input(p1,m);
    printf("Give input for Polynomial 2:\n");
    input(p2,n);
    poly_mul(p1,p2,m,n);
    return 0;
}
