//01. C Program to Swap Two Numbers.
#include<stdio.h>
#include<math.h>
#include<time.h>


int swap(){
    int a,b,c;
    printf("What is your first number??\n");
    scanf("%d",&a);
    printf("What is your second number??\n");
    scanf("%d",&b);
    c=b;
    b=a;
    a=c;
    printf("%d %d\n",a,b);
    return 0;
}
//02. C Program to Check Whether a Number is Positive, Negative, or Zero.
int check_posneg0(){
    int a;
    printf("What is the number to check?\n");
    scanf("%d",&a);
    if(a>0){
        printf("The number is positive.\n");
    }
    else if(a<0){
        printf("The number is negative.\n");
    }
    else printf("The number is 0");
    return 0;
} 

//C Program to Find Factorial of a Number.

int factorial(){
    int num,fact=1;
    printf("What number do you want to find the factorial of?\n");
    scanf("%d",&num);
    do{
        fact = fact*num;
        num--;
    }while(num>1);
    printf("%d\n",fact);
    return 0;
}

int fibonacci(){
    int i=0,j=1,n,num=0;
    printf("Till what number do you want to print the series?\n");
    scanf("%d",&n);
    num=i+j;
    printf("%d",i);
    for(i=3;i<=n;i++){
        printf("\n%d",num);
        
        i=j;
        j=num;
        num=i+j;

    }
    printf("\n");
    return 0;
}

//08. C Program to Check Armstrong Number.
int armstrong_number(){
    int num,op_num,last_dig_rem,sum=0,i=0;
    printf("What is the number you want to check?\n");
    scanf("%d",&num);
    op_num=num;
    while(pow(10,i)<num){
        i++;
    }
    while(op_num!=0){
        /*//remainder when divided by 10
        //(basically last digit of the number) in the first loop
    then the second to last digit in the second loop
    then check for the third to last and so on
        */
        last_dig_rem=op_num%10;
        sum += pow(last_dig_rem,i);
        op_num=op_num/10;
    }
    if (sum==num)
    {
        printf("%d is a armstrong number\n",num);
    }
    else{
        printf("%d is not a armstrong number\n",num);
    }
    return 0;
}
//09. C Program to Reverse a Number.
int reverse(){
    int num,i=0,sum=0,dig,op_num;

    printf("What is the number you want to reverse?\n");
    scanf("%d",&num);
    op_num=num;
    while (pow(10,i)<num)
    {
        i++;
    }
    while (op_num>0)
    {
        dig=op_num%10;
        sum+=dig*pow(10,i-1);
        op_num=op_num/10;
        i--;
    }
    
    printf("%d is the reversed number.\n",sum);

    return 0;
}
// 3 and 5 to do still.

// Put at digits in an ascending order.

// int ascending(){
//     int num,op_num,i=0;
//     printf("What number do you want to give?\n");
//     scanf("%d",&num);
//     num=op_num;
//     while (pow(10,i)<num)
//     {
//         i++;
//     }
    

//     return 0;
// }

int check_ternary(){
    int a;
    printf("What is the age?\n");
    scanf("%d",&a);
    a>18?printf("You are eligible to vote.\n"):printf("You are not eligible to vote.\n");

    return 0;
}

int bitwise(){
    int a=8,b=7,c;
    c=a&b;
    printf("%d\n",c);
    c=a|b;
    printf("%d\n",c);
    c=a^b;
    printf("%d\n",c);
    c=~b;
    printf("%d\n",c);

    return 0;
}

int time_check(){
    time_t begin=time(NULL);
    printf("Time Checking.\n");
    time_t end = time(NULL);
    printf("Time elapsed is %ld seconds.\n",end-begin);//ld long int
    return 0;
}

int fact(int a){
    int facto=1;
    while(a>=1){
        facto=facto*a;
        a--;
    }
    return facto;
}

int series_sum(){
    int n,r;
    double sum=0.0;
    // printf("What Factorial do you want??\n");
    // scanf("%d",&n);
    // a=fact(n);
    // printf("%d",a);
    printf("Till what value do you want to print the series?\n");
    scanf("%d",&n);
    while (n>0)
    {
        sum = sum+ 1.0/fact(n-1);
        n--;
    }
    printf("%f",sum);
    return 0;
}


int print_arms_tilln(){
    int n=0;
    int num=150,op_num,last_dig_rem,sum=0,i=0;
    printf("Till what number do you want to check?\n");
    scanf("%d",&n);

    while (n>150)
    {
        num=num+1;
        op_num=num;
        while(pow(10,i)<num){
            i++;
        }
        while(op_num!=0){
            last_dig_rem=op_num%10;
            sum += pow(last_dig_rem,i);
            op_num=op_num/10;
        }
        if (sum==num)
        {
            printf("%d\n",num);
        }
        n--;
    }
    

    return 0;
}

int quadratic_roots(){
    float a,b,c;
    float d,x,y;
    printf("Tell a,b,c:\n");
    scanf("%f %f %f",&a,&b,&c);
    d=pow(b,2)-4*a*c;
    if(d>=0){
        x=(-b+sqrt(d))/2.0*a;
        y=(-b-sqrt(d))/2.0*a;
        printf("%f %f\n",x,y);
    }
    else{
        x=(-b)/2.0*a;
        y=sqrt(-d)/2.0*a;
        printf("%f %fi\n",x,y);
        x=(-b)/2.0*a;
        y=-sqrt(-d)/2.0*a;
        printf("%f %fi\n",x,y);
                
    }
    return 0;
}

int sum_series_1_5_10_15(){
    //1 5 10 15..... n
    int n,sum=1,i;
    printf("What is n?\n");
    scanf("%d",&n);
    for(i=1;i<=n-1;i++){
        sum = sum + i*5;
    }
    printf("The sum is:%d\n",sum);
    return 0;
}

int pattern_star(){
    int n,i,j;
    printf("What is n?\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }  
    return 0;
}


int prime_number(){
    int n, flag=0,i,j;
    printf("What is n?\n");
    scanf("%d",&n);
    for(i=2;i<=n;i++){
        flag=0;
        for(j=2;j<=i/2;j++){
            if(i%j==0){
                flag=1;
                break;          
            }
        }
        if(flag==0){
            printf("%d\n",i);
        }
    }
    return 0;
}

int main(){
    // swap();
    // check_posneg0();
    // factorial();
    // fibonacci();
    // reverse();
    // ascending();
    // check_ternary();
    // bitwise();
    // time_check();
    //docharacters();
    // series_sum();
    // print_arms_tilln();
    // quadratic_roots();
    // sum_series_1_5_10_15();
    // pattern_star();
    // prime_number();
    return 0;
}


