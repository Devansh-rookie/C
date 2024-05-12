#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>
#define maxSize 100
char stk[maxSize];
int top = -1;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isOperator(char c){
    if(c == '^'||c == '/' || c == '*'||c == '+' || c == '-') return true;
    return false;
}

bool isEmpty(){
    if(top== -1) return true;
    return false;
}

bool isFull(){
    if(top == maxSize-1) return true;
    return false;
}

void push(char val){
    if(top == maxSize-1) return;
    stk[++top]= val;
}

char pop(){
    if(!isEmpty()){
        char a = stk[top--];
        return a;
    }
}

void inToPost(char *s){
    int i=0;
    // push('(');
    while(s[i]!='\0'){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')){
            printf("%c", s[i]);
        }
        else if(s[i]=='('){
            push(s[i]);
        }
        else if(s[i]==')'){
            char x= pop();
            while(x!='('){
                printf("%c", x);
                x = pop();
            }
        }
        else if(isOperator(s[i])){
            if(prec(stk[top])>=prec(s[i])){
                while (prec(stk[top])>=prec(s[i]))
                {
                    char x = pop();
                    printf("%c", x);
                }
            }
            push(s[i]);
        }
        i++;
    }
    while(!isEmpty()){
        if(stk[top]!='(')
            printf("%c", pop());
        else pop();
    }
}

int main(){
    char s[100];
    gets(s);
    inToPost(s);
    return 0;
}
