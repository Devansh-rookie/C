#include<stdio.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define maxsize 100
char stk[maxsize];
int top =-1;
int top_stk=-1;
char stak[100];
bool is_operator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^') return true;
    // else return false;
    return false;
}

void post_in(char s[]){
    int i=0;int j=0;
    char final[maxsize];
    while(s[i]!='\0'){
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
            stak[j++]= s[i];
        }
        else if(is_operator(s[i])){
            char operand1 = stak[j--];
            char operand2 = stak[j--];
            sprintf(final, "(%c%c%c)", operand1, s[i], operand2);
            stak[j++]= final[0];// means the entire current string should be in the stack. so stack should be a char array
        }
        i++;
    }
    printf("%s\n",final);
}

int main(){
    char s[100];
    fgets(s,100,stdin);
    post_in(s);
    return 0;
}
