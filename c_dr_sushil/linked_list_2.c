#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int val;
    struct Node * next;
}Node;

Node * first = NULL;
Node * last = NULL;

bool isEmpty(){
    if(first== NULL|| last == NULL) return true;
    return false;
}

void push(int val){
    Node * t = (Node *)malloc(sizeof(Node));
    t->val = val;
    t->next=NULL;// because we are inserting at the last place
    if(isEmpty()){
        first = t;
        last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}

int pop(){
    if(isEmpty()){ 
        printf("The stack is empty.");
        return INT32_MIN;
    }
    Node * p = first;
    int x;
    if(p->next==NULL){
        x=p->val;
        first = last= NULL;
        return x;
    }
    while(p->next!= last){
        p=p->next;
    }
    x=p->next->val;
    last = p;
    p->next = NULL;
    return x;
}

void display(Node * p){// using iterative method
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
}


int main(){
    push(10);
    push(20);
    push(30);
    display(first);
    printf("\n");
    printf("%d\n", pop());
    printf("%d\n", pop());
    push(50);
    display(first);
    printf("\n");
    return 0;
}
