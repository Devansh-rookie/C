#include<stdio.h>
#include<math.h>

int alpha_num_tri(){
    int a,i,j=1,k,l;
    printf("How many rows?\n");
    scanf("%d",&a);

    for(i=1;i<=a;i++){
        j=1;
        if(i%2!=0){
            for(;j<=i;j++){
                printf("%d",j);
            }
        }
        else{
            for ( k = 1; k <= i; k++)
            {
                l=k+64;
                char ch = (char)l;
                printf("%c",ch);
            }
            
        }
        printf("\n");
    }
    return 0;
}

int plus_print(){
    int n,i,j,k,space;
    printf("What is number of rows?\n");
    scanf("%d",&n);
    space=n/2;
    for (i = 1; i <= n; i++)
    {
        if(i==(n/2+1)){
            for(j=1;j<=n;j++){
                printf("*");
            }
            printf("\n");
        }
        else{
            for(k=1;k<=space+1;k++){
                printf(" ");
            }
            printf("*\n");//Print only n/2-1
        }
    }
    
    return 0;
}

int star_cross(){
    int n,i,j;
    printf("What is number of rows?\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j||i+j==n+1){//Look at it like a matrix the iterate over each one of the elements and check the index
                printf("*");
            }
            
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

int _1_0_triangle(){//look at it like a matrix
    int n,i,j;
    printf("What is number of rows?\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j>i){
                printf(" ");
            }
            else if((i+j)%2==0){
                printf("1");
            }
            else if((i+j)%2!=0){
                printf("0");
            }
        }
        printf("\n");
    }   
    return 0;
}

int star_triangle_(){
    int n,i,j;
    printf("What is number of rows?\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i+j>n){
                printf("*");
            }
            else{
                printf(" ");
            }
            
        }
        printf("\n");
    }

    return 0;
}

int rhombus_pattern(){
    int n,i,j,space,k;
    printf("What is number of rows?\n");
    scanf("%d",&n);   
    space =n-1; 
    for(i=1;i<=n;i++){
        for(j=1;j<=space;j++){
            // printf("*");
            printf(" ");

        }
        space--;
        for(k=1;k<=n;k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

int star_triangle_ABCD(){
    int n,i,j,l,k;
    char abc;
    printf("What is number of rows?\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        k=1;
        for(j=1;j<=n;j++){
            if(i+j>n){
                
                l=k+64;
                abc=(char)l;
                printf("%c",abc);
                k++;
                
            }
            else{
                printf(" ");
            }
            
            
        }
        printf("\n");
    }

    return 0;
}


int pyramid_print(){
    int n,i,j,k,space;// since we are in 2D we would most likely require both i and j
    printf("What is number of rows?\n");
    scanf("%d",&n);
    space=n;
    for(i=1;i<=n;i++){
        space=n;
        for ( j = 1; j <= space-i; space--)
        {
            printf(" ");
        }
        for (k = 1; k <= 2*i-1; k++)
        {
            printf("*");
        }
        printf("\n");
        
    }
    return 0;
}


int number_pyramid_oddcolumns(){
    int n,i,j,k,space;
    
    printf("What is number of rows?\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        space=n;//reset space for reduction in the for loop
        for(j=1;j<=space-i;j++){
            printf(" ");
        }
        for(k=1;k<=2*i-1;k++){
            printf("%d",k);
        }
        printf("\n");
    }


    return 0;
}


int number_pattern_1_121(){//This could also be easily converted into Alphabet triangle using ASCII code and i/j/k+64.
    int n,i,j,k,space;//because ASCII of 'A' is 65 and 'a' is 97
    printf("What is number of rows?\n");
    scanf("%d",&n);
    for ( i = 1; i <= n; i++)
    {
        space=n;
        for(j=1;j<=space-i;j++){
            printf(" ");
        }
        for(k=1;k<=i;k++){
            printf("%d",k);
        }
        for(k=i-1;k>0;k--){
            printf("%d",k);
        }
        printf("\n");
    }
    return 0;
}

int star_diamond(){
    int n,space,i,j,k;
    printf("What is number of rows?\n");
    scanf("%d",&n);
    space=n;
    for(i=1;i<=2*n-1;i++){
        if(i<=n){
            space=n;
            for ( j = 1; j <= space-i; j++)
            {
                printf(" ");
            }
            for (k = 1; k <= 2*i-1; k++)
            {
                printf("*");
            }
            printf("\n");
            }
        else{
            space=n;
            for ( j = 1; j <= i-n; j++)
            {
                printf(" ");
            }
            for (k = 2*(2*n-i)-1; k >0; k--)
            {
                printf("*");
            }
            printf("\n");
            }
        }
    return 0;
}
int two_inverted_pyramids(){
    int n,i,j,k;

    printf("What is number of rows?\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=2*n-1;j++){
            if((j!=(2*n-1)/2)){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

int number_zoom(){
    int n,i,j;
    printf("What is the number?\n");
    scanf("%d",&n);

    for(i=1;i<=2*n-1;i++){
        for(j=1;j<=2*n-1;j++){

        }
    }
    return 0;
}


int pyramid_arith(){
    int n,i,j,space,k;
    printf("What is the number of rows?\n");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        space=n;
        for ( j = 1; j<=space-i; j++)
        {
            printf(" ");
        }
        for ( k = 1; k <= i; k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}


int prime_theorem(){
    int n,i,j;
    printf("Number:\n");
    scanf("%d",&n);
    j=n;
    for(i=2;i<=n/2+1;i++){
        while(j%i==0){
            j=j/i;
            printf("%d ",i);
        }
    }
    return 0;
}

int main(){
    //PW Video https://www.youtube.com/watch?v=clIcH1ALHMw
    // alpha_num_tri();
    // plus_print();
    // star_cross();
    // _1_0_triangle();
    // star_triangle_();
    // rhombus_pattern();
    // star_triangle_ABCD();
    // pyramid_print();
    // number_pyramid_oddcolumns();
    // number_pattern_1_121();
    // star_diamond();
    // two_inverted_pyramids();//have to do this question again Q25 in the PW Video
    // number_zoom();
    // pyramid_arith();
    prime_theorem();
    return 0;
}

