#include<stdio.h>
#include<stdbool.h>
#define maxsize 100
int stk[maxsize];
int top =-1;


bool is_operator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^') return true;
    // else return false;
    return false;
}

int priority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    // else return 0;
    return 0;
}

void infix_postfix(char s[]){
    char ans[100];
    int i=0,j=0;
    while (s[i]!='\0')
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z')){
            ans[j++]= s[i];
        }
        else if(is_operator(s[i])){
            if(priority(stk[top])>=priority(s[i])){
                while (top>=0)
                {
                    ans[j++]= stk[top--];
                    // or j++ and 'j' in ans[j]
                }
            }
            else stk[++top]=s[i];
        }
        else if(s[i]=='('){
            stk[++top]= s[i];
        }
        else if(s[i]==')'){
            while (top>=0&& stk[top]!='(')
            {
                ans[j++]=stk[top--];
            }
            top--; // remove '('
        }
        i++;
    }
    while (top>=0)
    {
        ans[j++]=stk[top--];
    }
    ans[j++]='\0';
    puts(ans);
}

int main(){
    char s[100];
    fgets(s,100,stdin);
    infix_postfix(s);
    return 0;
}

