#include<stdio.h>
#include<string.h>
typedef struct date{
    int date;
    int month;
    int year;
}date;

void compare_date(){
    date d1,d2;
    printf("Enter the date, month and year(in numbers)\n");
    scanf("%d %d %d",&d1.date,&d1.month,&d1.year);
    printf("Enter the date, month and year(in numbers)\n");
    scanf("%d %d %d",&d2.date,&d2.month,&d2.year);
    if(d1.date==d2.date&&d1.month==d2.month&&d1.year==d2.year){
        printf("EQUAL\n");
    }
    else printf("UNEQUAL\n");
}

// Yes relational operators can be used on a string 
// but it will be done lexicographically which means that
// it will use ASCII code starting from the first letter and going
// on till the last and if the strings are A and B so if 
// A[0]>B[0](in ASCII code) the the function of Strcmp
// would return the value of 1 is A[0] is smaller
// then -1 other wise if its equal then it will go to A[1]
// and B[1] then again and again go through if all are equal
// then it would have 0 otherwise 1 or -1 as shown above.

// do array question find how many times a thing has been repeated

void remove_except_alpha(){
    char a[100],b[100];
    // gets(a);
    int i=0,j=0;
    fgets(a,100,stdin);// stdin for input
    while(a[i]!='\0'){// copying the alphabet values
    // another method can be to delete the rest
        if((a[i]<=90&&a[i]>=65)||(a[i]<=122&&a[i]>=97)){
            b[j]=a[i];
            j++;
            }
        i++;
    }
    puts(b);
}

void transpose(){
    int row,col;
    printf("Enter the number of rows and columns\n");
    scanf("%d %d",&row,&col);
    int a[row][col], b[col][row];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            b[j][i]=a[i][j];
        }
    }
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}

void question_switchcase(){
    int i=4;

    switch (i)
    {
    case 4:
        i+=4;
        printf("%d ",i);
    case 8:
        i+=4;
        printf("%d ",i);
    
    default:
        i++;
        printf("%d ",i);
        break;
    }
}

void es_pattern(){
    int i=0,j=0,n,c=1;
    scanf("%d",&n);
    int a=n*(n-1)/2;
    for(i=1;i<=n;i++){
        for(j=n;j>i;j--){
            printf(" ");
        }
        for(j=i;j>0;j--){
            printf("%d ",c);
            c++;
        }
        printf("\n");
    }
    for(i=1;i<=n-1;i++){
        for(j=1;j<=i;j++){
            printf(" ");
        }
        for(;a>(n-i-1)*(n-i)/2;a--){
            printf("%d ", a);
        }
        printf("\n");
    }
}

void pattern_pyramid(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=n;j>i;j--){
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }
}

void number_pyramid(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=n;j>i;j--){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        for(j=i-1;j>0;j--){
            printf("%d",j);
        }
        printf("\n");
    }
}

void square_pyra(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=n-i;j>0;j--){
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }
    for(i=1;i<=n-1;i++){
        for(j=1;j<=i;j++){
            printf(" ");
        }
        for(j=2*(n-i)-1;j>0;j--){
            printf("*");
        }
        printf("\n");
    }
}

void good_pyramid(){
    int i,j,n;
    scanf("%d",&n);

    for(i=1;i<=2*n-1;i++) printf("*");
    printf("\n");
    for(i=n-1;i>=1;i--){
        for(j=i;j>0;j--){
            printf("*");
        }
        for(j=1;j<=2*(n-i)-1;j++){
            printf(" ");
        }
        for(j=i;j>0;j--){
            printf("*");
        }
        printf("\n");
    }
}

void better_pyramid(){
    int i,j,n,a;
    scanf("%d",&n);
    for(i=1;i<=2*n-1;i++) printf("%d",i);
    printf("\n");
    for(i=1;i<=2*(n-1)-1;i++){
        a=0;
        for(j=1;j<=n-i;j++){
            printf("%d",j);
            a++;
        }
        for(j=1;j<=2*i-1;j++){
            printf(" ");
            a++;
        }
        for(j=1;j<=n-i;j++){
            a++;
            printf("%d",a);
        }
        printf("\n");
    }
}

void string_question(){
    char a[100],b[100];
    int l=0,j=0;
    fgets(a,100,stdin);
    while(a[l]!='\0'){
        l++;
    }
    for(int i=0;i<l;i++){
        b[0]=a[0];
        if(a[i]== ' '){// " " represents a string while ' ' is a character 
            j++;
            b[j]=a[i+1];
        }
    }
    puts(b);
}

void even_better_pyramid(){
    int i,j,n,a,flag;
    scanf("%d",&n);
    for(i=1;i<=n;i++) printf("%d",i);
    for(i=n-1;i>0;i--) printf("%d",i);
    printf("\n");
    for(i=1;i<=n-1;i++){// as we already had the first line it now has only n-1 lines
        a=0;
        flag=0;
        for(j=1;j<=n-i;j++){
            a++;
            printf("%d",a);
        }
        for(j=1;j<=2*i-1;j++){// as n-1 not n so will work with 2*i-1 otherwise we ahd to use 2*i-3
            printf(" ");
            if(a<n && flag==0){
                a++;
            }
            else {
                a--;
                flag=1;
            }    
        }
        for(j=1;j<=n-i;j++){
            a--;
            printf("%d",a);
        }
        printf("\n");
    }
}

void transpose_no_othermatrix(){
    int i,j,row,col;
    int arr[100][100];
    scanf("%d %d",&row,&col);
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<row;i++){
        for(j=i;j<col;j++){// start j from i VVIP
            int temp= arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    for(i=0;i<col;i++){
        for(j=0;j<row;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

void hollow_pyra(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=2*n-1;i++) printf("*");
    printf("\n");
    for(i=1;i<=n-1;i++){
        for(j=1;j<=n-i;j++){
            printf("*");
        }
        for(j=1;j<=2*i-1;j++){
            printf(" ");
        }
        for(j=1;j<=n-i;j++){
            printf("*");
        }
        printf("\n");
    }
    // for(i=1;i<=n-1;i++){// start from 1(even rows)
    //     for(j=1;j<=i;j++) printf("*");
    //     for(j=1;j<=2*(n-i)-1;j++){
    //         printf(" ");
    //     }
    //     for(j=1;j<=i;j++) printf("*");
    //     printf("\n");
    // }
    for(i=2;i<=n-1;i++){// start from 2(odd rows)
        for(j=1;j<=i;j++) printf("*");
        for(j=1;j<=2*(n-i)-1;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++) printf("*");
        printf("\n");
    }
    for(i=1;i<=2*n-1;i++) printf("*");
}

void rishab_pyra(){
    int i,j,n;
    scanf("%d",&n);
    // for(i=1;i<=n;i++){
    //     for(j=1;j<=n-i;j++){// start n-i ,>0or n to j>=i, j--
    //         printf(" ");
    //     }
    //     for(j=1;j<=i;j++){
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    for(i=1;i<=n;i++){// or uuse 0 and remove equal to
        for(j=1;j<=n;j++){
            if(((i+j)>=n+1)){// (p+q-2)
                printf("*");
            }
            else printf(" ");
        }
        printf("\n");
    }
}

void question_pointer(){
    // int a[50][40];
    // printf("%u\n",a);
    // printf("%u\n",&a[40][30]);
}

int fact(int n){
    int factorial=1;
    for(int i=1;i<=n;i++) factorial*=i;
    return factorial;
}

int nCr(int n,int r){
    int ans;
    ans = fact(n)/(fact(r)*fact(n-r));
    return ans;
}

void pascal_triangle(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        for(j=i;j<=n;j++){
            printf(" ");
        }
        for(j=0;j<=i;j++){
            printf("%d ",nCr(i,j));
        }
        printf("\n");
    }
}

void fibbonacci(){
    int s1,s2,sum,n,i=1;
    scanf("%d",&n);
    s1=0;
    s2=1;
    printf("%d %d ",s1,s2);
    // while(i<=n){
    //     sum=s1+s2;
    //     printf("%d ",sum);
    //     int temp = s2;
    //     s2=sum;
    //     s1=temp;
    //     i++;
    // }
    do{
        sum=s1+s2;
        printf("%d ",sum);
        int temp = s2;
        s2=sum;
        s1=temp;
        // i++;
    }while(sum!=n);
}

int sum_ascii(char str[]){
    int l= strlen(str);
    int sum=0;
    for(int i=0;i<l;i++){
        sum = sum + str[i];
    }
    return sum;
}

void alphabet_pattern(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf(" ");
        }
        for(j=i;j<=n;j++){
            printf("%c ",j+64);
        }
        printf("\n");
    }
}

void swap(){
    int a,b;
    scanf("%d %d",&a,&b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("%d %d",a,b);
}

void bubble_sort(){
    int n,i,j;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    for(i=0;i<n-1;i++){
        for(j=i;j<n;j++){
            if(arr[i]<arr[j]){// asc, for desc arr[j] is greater 
                arr[i]=arr[i]^arr[j];// swapping using binary
                arr[j]=arr[i]^arr[j];
                arr[i]=arr[i]^arr[j];
            }
        }
    }
    for(i=0;i<n;i++) printf("%d ",arr[i]);
}

int main(){
    // remove_except_alpha();
    // transpose();
    // question_switchcase();
    // es_pattern();
    // pattern_pyramid();
    // number_pyramid();
    // square_pyra();
    // good_pyramid();
    // better_pyramid();
    // string_question();
    // even_better_pyramid();
    // transpose_no_othermatrix();
    // hollow_pyra();
    // rishab_pyra();
    // question_pointer();
    // pascal_triangle();
    // fibbonacci();
    // char abc[100];
    // gets(abc);
    // printf("%d",sum_ascii(abc));
    // alphabet_pattern();
    // swap();
    // bubble_sort();
    return 0;
}