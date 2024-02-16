#include<stdio.h>
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
    else return;
}

bool check_for_1(int n){
    int op_num = n;
    bool flag = true;
    while(op_num!=0){
        if(op_num%10!=1 && op_num%10!=0){
            op_num/=10;
        }
        else{
            return true;
        }
    }
    return false;
}



int main(){
    // for i in strlen(of the returned string then let it have all the permutations)
    int i,j;
    int n;
    if(!check_for_1(n)){
        for(i=0;;){
            
        }
    }
    return 0;
}
