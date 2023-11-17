#include<stdio.h>
#include<math.h>

int ques_1(){
    int n,i,j,k,space,l;

    printf("What is the number of rows?\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        space=n;
        for(j=1;j<=space-i;j++){
            printf(" ");
        }
        for ( k = i; k >0 ; k--)
        {
            printf("%d",k);
        }
        for ( l =2 ; l <=i; l++)
        {
            printf("%d",l);
        }
        
        printf("\n");
        
    }
    return 0;
}



int ques_2(){
    int n,i,j,flag=0;
    printf("What is the number that you want to print the prime factors of?\n");
    scanf("%d",&n);
    if(n%2==0){
        printf("2\n");
    }
    for(i=2;i<=n/2+1;i++){
        flag =0;
        if(n%i==0){
            // printf("%d\n",i);
            for(j=2;j<=i/2+1;j++){
                if(i%j==0){
                    flag =1;
                    break;
                }

            }
            if(flag==0){
                printf("%d\n",i);
            }
        }
    }    
    return 0;
}
int fact(int n){
    int i,facto=1;
    for(i=1;i<=n;i++){
        facto=facto*i;
    }
    return facto;
}

int ques_3(){
    int n,i;
    float x,sum=0.0;
    printf("What is X?\n");
    scanf("%f",&x);
    printf("What is N?\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        if(i%2==0){
            sum = sum +(pow(x,i)/fact(i));
        }
        else{
            sum = sum -(pow(x,i)/fact(i));
        }
        
    }
    printf("The sum is:%f\n",sum);
    return 0;
}

int ques_4(){
    int n,i,j;
    printf("What is the number of rows?\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j>=i){
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

int ques_2_improved(){
    int n,i,j,flag=0;
    printf("What is the number that you want to print the prime factors of?\n");
    scanf("%d",&n);
    if(n%2==0){
        printf("2\n");
    }
    for(i=2;i<=n/2+1;i++){
        flag =0;
        if(n%i==0){
            // printf("%d\n",i);
            for(j=2;j<=i/2+1;j++){
                if(i%j==0){
                    flag =1;
                    break;
                }

            }
            if(flag==0){
                printf("%d\n",i);
            }
        }
    }    
    return 0;

}

int prime(int n){
    int i,flag=0;
    for(i=2;i<=n/2+1;i++){
        if(n%i==0){
            flag++;
        }
    }
    if(flag==0){
        return 1;
    }
    return 0;
}

int diff(){
    int n,i,j,flag=0, op_num,k;
    printf("What is the number that you want to print the prime factors of?\n");
    scanf("%d",&n);
    op_num=n;
    if(op_num>1){
        for(i=2;i<=n/2+1;i++){
            op_num=n;
            flag=0;
            if (op_num>1)
            {
                for(j=0;j<=n;j++){
                    flag=0;
                    // op_num/=i;
                    if (op_num%i==0)
                    {
                        // printf("%d\n",i);
                        // op_num/=i;
                        for ( k = 2; k<=i/2+1; k++)
                        {
                            if(i%k==0&&k!=2){
                                continue;
                            }
                            else{
                                flag++;
                                break;
                            }
                            // printf("%d\n",i);
                            // op_num/=i;
                        }
                        if(prime(i)){
                            printf("%d\n",i);
                            op_num/=i;
                        }
                        // printf("%d\n",i);
                        // op_num/=i;
                    }
                    
            }

            }
            
        }
    }
    return 0;
}


int main(){
    // ques_1();
    // ques_2();
    // ques_3();
    // ques_4();
    // ques_2_improved();
    diff();
    return 0;
}

