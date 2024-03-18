#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *first1 = NULL;
Node *first2 = NULL;

void display(Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        display(p->next);
    }
}

void create1(int a[], int n){
    int i;
    Node *t, *last;
    // linked_list* first = (linked_list*)malloc(sizeof(linked_list)); redeclaration main dikkat
    first1 = (Node*)malloc(sizeof(Node));
    first1->data= a[0];
    first1->next= NULL;
    last = first1;
    for(i=1;i<n;i++){
        Node* t = (Node*)malloc(sizeof(Node));
        t->data=a[i]; // as the zeroth element is already added to the linked list
        t->next=NULL;
        last->next=t;// this is assigned to the last t/ the pointer of the next object in the last value
        last = t;// this is being assigned to a new t
    }
}

void create2(int a[], int n){
    int i;
    Node *t, *last;
    // linked_list* first = (linked_list*)malloc(sizeof(linked_list)); redeclaration main dikkat
    first2 = (Node*)malloc(sizeof(Node));
    first2->data= a[0];
    first2->next= NULL;
    last = first2;
    for(i=1;i<n;i++){
        Node* t = (Node*)malloc(sizeof(Node));
        t->data=a[i]; // as the zeroth element is already added to the linked list
        t->next=NULL;
        last->next=t;// this is assigned to the last t/ the pointer of the next object in the last value
        last = t;// this is being assigned to a new t
    }
}

void merging(Node * p1, Node * p2){
    Node * p_f=NULL;Node * p_s= NULL;
    p_f= p1;
    p_s = p2;
    Node* print = p1;
    Node * new = NULL;
    Node * new2 = NULL;
    while(p_f!=NULL && p_s != NULL){
        new=p_f->next;
        p_f->next = p_s;
        // p_f->next= new;
        new2 = p_s->next;
        p_s->next=new;
        p_s = new2;
        p_f=new;
        // check the next pointer such that if its NULL break and do the remaining condition in the if statement
    }
    if(p_s!=NULL && p_f==NULL)
    {
        p_f->next= p_s;
    }
    else if(p_f!=NULL && p_s==NULL){
        p_s->next = p_f;
    }
    display(print);
}

int main(){
    int a[]= {1,5,3,5,6,7,11};
    int b[] = {5,3,1,4,9,10,8,9,5,3};
    create1(a,7);
    create2(b,10);
    merging(first1, first2);
    return 0;
}
