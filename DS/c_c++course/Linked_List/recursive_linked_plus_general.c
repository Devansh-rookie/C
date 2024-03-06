#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *first = NULL;


void create(int a[], int n){
    int i;
    Node *t, *last;
    // linked_list* first = (linked_list*)malloc(sizeof(linked_list)); redeclaration main dikkat
    first = (Node*)malloc(sizeof(Node));
    first->data= a[0];
    first->next= NULL;
    last = first;
    for(i=1;i<n;i++){
        Node* t = (Node*)malloc(sizeof(Node));
        t->data=a[i]; // as the zeroth element is already added to the linked list
        t->next=NULL;
        last->next=t;// this is assigned to the last t/ the pointer of the next object in the last value
        last = t;// this is being assigned to a new t
    }
}

void display(Node *p){
    if(p!=NULL){
        printf("%d ", p->data);
        display(p->next);
    }
}

int count_rec(Node *p){// O(n)- Time and O(n)- Space
    if(p!=NULL){
        return count_rec(p->next)+1;
    }
    else return 0;
}

int count(Node *p){// O(n)- Time  and O(1)- Space
    int c=0;
    while (p!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}

int sum_iterative(Node *p){
    int sum= 0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int sum_recursive(Node *p){
    
}

int main(){
    int a[5]= {2,1,4,5,3};
    create(a,5);
    display(first);
    printf("\n%d", count_rec(first));
    printf("\n%d", count(first));
    printf("\n%d", sum_iterative(first));
    printf("\n%d", sum_recursive(first));
    return 0;
}
