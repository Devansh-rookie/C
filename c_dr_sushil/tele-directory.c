#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

char *num_to_string(int n){
    if(n==2) return "ABC";
    else if(n==3) return "DEF";
    else if(n==4) return "GHI";
    else if(n==5) return "JKL";
    else if(n==6) return "MNO";
    else if(n==7) return "PQRS";
    else if(n==8) return "TUV";
    else if(n==9) return "WXYZ";
    else return "0";
}


void all_pnc(int x){
    FILE *fp;
    fp = fopen("tele-directory.txt","w");
    int op_num =x, dig = 7;
    int b[7];
    while (dig!=0)
    {
        b[7-dig]=(int)(op_num/(int)pow(10,dig-1));
        op_num=op_num%(int)pow(10,dig-1);
        dig--;
    }
    // for(int i=0;i<7;i++){
    //     printf("%d ",b[i]);
    // }

    // try to use recursion to use loop in loop with a reversed integer array as the compilation is through a stack
    char q[8];
    for(int i=0;num_to_string(b[0])[i]!='\0';i++){
        q[0]=num_to_string(b[0])[i];
        for(int i1=0;num_to_string(b[1])[i1]!='\0';i1++){
            q[1]=num_to_string(b[1])[i1];
            for(int i2=0;num_to_string(b[2])[i2]!='\0';i2++){
                q[2]=num_to_string(b[2])[i2];
                for(int i3=0;num_to_string(b[3])[i3]!='\0';i3++){
                    q[3]=num_to_string(b[3])[i3];
                    for(int i4=0;num_to_string(b[4])[i4]!='\0';i4++){
                        q[4]=num_to_string(b[4])[i4];
                        for(int i5=0;num_to_string(b[5])[i5]!='\0';i5++){
                            q[5]=num_to_string(b[5])[i5];
                            for(int i6=0;num_to_string(b[6])[i6]!='\0';i6++){
                                q[6]=num_to_string(b[6])[i6];
                                q[7]='\0';
                                fprintf(fp,"%s\n",q);
                            }
                        }
                    }
                }   
            }
        }
        
    }
}

int main(){
    int x;
    printf("What is the 7 Digit number to use for All P&C: ");
    scanf("%d",&x);
    all_pnc(x);
    printf("Print in file successful.");
    return 0;
}
