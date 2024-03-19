#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node * next;
}Node;

Node * head1=NULL;
Node * head2= NULL;
Node * last1= NULL;
Node * last2= NULL;

void insertAtLast(Node ** p,Node ** last,int num){
    Node * t = (Node *)malloc(sizeof(Node));
    t->val = num;
    t->next = NULL;
    if(*p ==NULL && * last == NULL){
        (*p)= t;
        (*last)= t;
    }
    else{
        (*last)->next = t;
        (*last)= t;
    }
}

void concatenate(Node * p , Node * q){
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = q;
}

void display(Node * p){
    while(p!=NULL){
        printf("%d ", p->val);
        p=p->next;
    }
}

int main(){
    insertAtLast(& head1,&last1,10);
    insertAtLast(&head1,&last1,20);
    insertAtLast(&head1,&last1,30);
    
    insertAtLast(&head2,&last2, 70);
    insertAtLast(&head2,&last2,90);
    display(head1);
    printf("\n");
    display(head2);
    concatenate(head1, head2);
    printf("\n");
    display(head1);
}
