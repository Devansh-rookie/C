#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define maxsize 100

int temp[maxsize];
int stk[maxsize];
int top = -1;
int temp_top=-1;

int is_empty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

int is_empty_tmp(){
    if(temp_top == -1){
        return 1;
    }
    return 0;
}


int is_full(){
    if(top == maxsize-1) return 1;
    return 0;
}

int is_full_tmp(){
    if(temp_top == maxsize-1) return 1;
    return 0;
}

void push(int x){// if we use structure here we can use any stricture with this function.
    if(!is_full()) stk[++top]= x;
    // here ++stk means pre increment that means that first we increment the number then we assign the value so it also changes top and it also assigns x to the stk value.
    else printf("The stack is full");
}

void push_tmp(int x){// if we use structure here we can use any stricture with this function.
    if(!is_full_tmp()) temp[++temp_top]= x;
    // here ++stk means pre increment that means that first we increment the number then we assign the value so it also changes top and it also assigns x to the stk value.
    else printf("The stack is full");
}

int pop(){
    if(!is_empty()){
        int v = stk[top];
        top--;
        return v;
    }
    else printf("The stack is empty");
    return 0;
}

int pop_tmp(){
    if(!is_empty_tmp()){
        int v = temp[temp_top];
        temp_top--;
        return v;
    }
    else printf("The stack is empty");
    return 0;
}

void peek(int pos){
    int index = top +1 - pos;
    if(!is_empty()) printf("%d",stk[index]);
    else printf("The stack is empty");
}

int stack_top(){
    if(!is_empty()) return stk[top];
    return INT_MIN;
}

bool check_parenthesis(char s[]){
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push_tmp(s[i]);
        }
        else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(temp[temp_top]=='(' && s[i]== ')') pop_tmp();
            else if(temp[temp_top]=='{' && s[i]== '}') pop_tmp();
            else if(temp[temp_top]=='[' && s[i]== ']') pop_tmp();
            else return false; // Brilliant to check for the cases where only ] is present not the entire thing
        }
        i++;
    }
    if(is_empty_tmp()){
        return true;
    }
    else return false;
}

int main(){
    char s[100];
    fgets(s,100,stdin);
    if(check_parenthesis(s)) printf("Valid");
    else printf("Not Valid");
    return 0;
}
