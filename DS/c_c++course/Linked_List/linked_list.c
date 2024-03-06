#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list* next;
} linked_list;

linked_list *first= NULL;

void display(linked_list *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void create(int a[], int n){
    int i;
    linked_list *t, *last;
    // linked_list* first = (linked_list*)malloc(sizeof(linked_list)); redeclaration main dikkat
    first = (linked_list*)malloc(sizeof(linked_list));
    first->data= a[0];
    first->next= NULL;
    last = first;
    for(i=1;i<n;i++){
        linked_list* t = (linked_list*)malloc(sizeof(linked_list));
        t->data=a[i]; // as the zeroth element is already added to the linked list
        t->next=NULL;
        last->next=t;
        last = t;
    }
}

int main(){
    int a[] = {3,5,7,10,15};
    create(a,5);
    display(first);
    return 0;
}

