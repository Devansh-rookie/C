#include<stdio.h>
#include<math.h>

int armstrong_series(){
    int n, sum=0, last_dig=0, num=0, op_num=0, j=0,i=0;
    printf("What is the number you want to print till?\n");
    scanf("%d",&n);
    for(j=0;j<=n;j++){
        num++;
        op_num=num;
        i=0;
        sum=0;

        while(pow(10,i)<num){
            i++;
            // printf("i%d ",i);

        }
        while (op_num!=0)
        {
            last_dig=op_num%10;
            sum= sum +pow(last_dig,i); 
            op_num/=10;
        }
        // printf("%d\n",sum);

        if(sum==num){
            printf("%d\n",num);
        }
    }
    return 0;
}


int shift_op(){
    int a,b,c;
    printf("Tell a and b:(for right shift)\n");
    scanf("%d %d",&a,&b);
    c=a>>b;
    printf("%d\n",c);
    printf("Tell a and b:(for left shift)\n");
    scanf("%d %d",&a,&b);
    c=a<<b;
    printf("%d\n",c);
    return 0;
}



int main(){
    // armstrong_series();
    // shift_op();
    return 0;
}

