#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node * next;
}Node;

Node * first = NULL;

void insert_at_beg(int val){
    // Node * t = (Node *)calloc(1,sizeof(Node));
    Node * t = (Node *)malloc(sizeof(Node));
    t->val = val;
    t->next = first;
    first = t;
    // free(t); // won't work here don't know why, maybe because free is not required here
}

void display(Node * p){// using iterative method
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
}

int main(){
    insert_at_beg(10);
    insert_at_beg(20);
    insert_at_beg(30);
    display(first);
    printf("\n");
    insert_at_beg(40);
    display(first);
    return 0;
}
