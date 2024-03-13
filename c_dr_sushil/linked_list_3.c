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

void insert_last(int val){
    Node *t = (Node*)malloc(sizeof(Node));
    t->val= val;
    t->next= NULL;

    if(first== NULL) first= last = t;
    else{
        last->next = t;// this is to link the current Node that is last to the next Node that is t.
        last = t;// then last to t
    }
}

void reverseSlidingPointer(Node * p){
    Node * q= NULL;Node * r = NULL;
    while(p!=NULL){
        r= q;
        q=p;
        // r's work is to be the tail to q and be pointed to by q->next; so the list is reversed
        // q->next would point to the previous Node that is r (its tail)
        // p is just to traverse the linked list
        p=p->next;

        q->next = r;// point backwards
        // p=p->next;// won't work as we first have to move all the pointers to their next spot then q->next = r; otherwise p and q are coinciding in the position.so if we change the q->next= r it also means that p->next is also changed so it will only show the first element there as only the first element is reversed.
        // IMAGINE IT!!! with pointers or draw it, will understand it better.
    }
    first = q;
}

void display(Node * p){
    while(p!=NULL){
        printf("%d ", p->val);
        p=p->next;
    }
}

int main(){
    insert_last(10);
    insert_last(20);
    insert_last(30);
    insert_last(40);
    insert_last(50);
    display(first);
    printf("\n");
    reverseSlidingPointer(first);
    display(first);
    printf("\n");
    return 0;
}
