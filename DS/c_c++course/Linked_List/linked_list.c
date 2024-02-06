#include<stdio.h>

typedef struct linked_list
{
    int data;
    linked_list* next;
} linked_list; *first =NULL;

linked_list *first = NULL;

void display(linked_list *p){
    while(p->next!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void create(linked_list *p){
    
}

int main(){
    linked_list* p;
    create(p);
    display(p);
    return 0;
}
