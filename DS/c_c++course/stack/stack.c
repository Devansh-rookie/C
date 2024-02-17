#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define maxsize 100

int stk[maxsize];
int top = -1;

bool is_empty(){
    if(top == -1){
        return true;
    }
    return false;
}

bool is_full(){
    if(top == maxsize-1) return true;
    return false;
}

void push(int x){// if we use structure here we can use any stricture with this function.
    if(!is_full) stk[++top]= x;
    // here ++stk means pre increment that means that first we increment the number then we assign the value so it also changes top and it also assigns x to the stk value.
    else printf("The stack is full");
}

void pop(){
    if(!is_empty){
        int v = stk[top];
        top--;
        return v;
    }
    else printf("The stack is empty");
}

void peek(int pos){
    int index = top +1 - pos;
    if(!is_empty) printf("%d",stk[index]);
    else printf("The stack is empty");
}

int stack_top(){
    if(!is_empty) return stk[top];
    return INT_MIN;
}

int main(){

    return 0;
}
