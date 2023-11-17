#include<stdio.h>
#include<math.h>

int calculator(){
    int ch=5,operator;
    float a,b;

    while (ch==5)
    {
    printf("What are the 2 numbers you want to operate on?\n");
    scanf("%f %f",&a,&b);
    printf("What operator would you like to use \n1.+\n2.-\n3.*\n4./\n");
    scanf("%d",&operator);
        switch (operator)
        {
        case 1:
            printf("%f\n",a+b);
            break;
        case 2:
            printf("%f\n",a-b);
            break;
        case 3:
            printf("%f\n",a*b);
            break;
        case 4:
            printf("%f\n",a/b);
            break;
        default:
            printf("\nPlease input the correct value.");
            break;
        }
        printf("\nInput 5 to continue or any other key to exit.\n");
        scanf("%d",&ch);
    }
    
    
    return 0;
}

int max(){
    int a,b,c;
    printf("What is a?\n");
    scanf("%d",&a);
    printf("What is b?\n");
    scanf("%d",&b);
    printf("What is c?\n");
    scanf("%d",&c);
    if(a>b){
        if(b>c){
            printf("Max is %d",a);
        }
        else if(c>a){
            printf("Max is %d",c);
        }
    }
    else if(b>a){
        if(b>c){
            printf("Max is %d",b);
        }
        else if(c>b){
            printf("Max is %d",c);
        }
    }
    return 0;
}


// int number_zoom(){
//     int i,j;
//     for(i=1;i<=2*4-1;i++){
//         for(j=1;j<=7;j++){
//             if((i==1||i==7)||(j==1||j==7)){
//                 printf("4");
//             }
//             if(((i==2||i==6)&&(j!=1||j!=7))||){
//                 printf("3");
//             }
//             if((i==1||i==7)||(j==1||j==7)){
//                 printf("2");
//             }
//             if((i==1||i==7)||(j==1||j==7)){
//                 printf("1");
//             }
                                    
//         }
//     }
//     return 0;
// }


int check_number(){
    int n,a,op_num,i,last_dig,j,p=0;
    printf("What is the number?\n");
    scanf("%d",&n);
    printf("What is the digit to check?\n");
    scanf("%d",&a);

    op_num=n;
    while(op_num>0){
        op_num/=10;
        i++;
    }
    op_num=n;
    for(j=1;j<=i;j++)
    {
        last_dig=op_num%10;
        op_num/=10;
        if(last_dig==a)
        {
            p=p+1;
            break;
        }
    }
    if ( p!=0)
    {
       printf("yes");
    }
    else 
    {
        printf("no");
    }
    return 0;
}




int main(){
    // calculator();
    // max();
    // check_number();
    return 0;
}
//%%, // this is how to print, single % is always a special character however if we ype it twice it will print %
