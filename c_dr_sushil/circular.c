#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include<stdbool.h>

typedef struct node
{
    int val;
    struct node * next;
}node;

bool isEmpty(node * first){
    if(first == NULL) return true;
    return false;
}

void insert(node ** first, node ** last, int val, int index){
    node * t = (node *)malloc(sizeof(node));
    t->val = val;
    if(*first == NULL){
        (*first) = t;
        (*last)=t;
        t->next = *first;
        return;
    }
    if(index== 0){
        t->next = (*first);
        (*first) = t;
        (*last)->next = t;
        return;
    }
    node * p = *first;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    if(p->next == *first){
        t->next = p->next;
        p->next = t;
        (*last) = t;
        return;
    }
    t->next = p->next;
    p->next = t;
}

void display(node * first){
    node * p = first;
    printf("\n");
    do {
        printf("%d ", p->val);
        p=p->next;
    }while (p!=first);
    printf("\n");
}

void delete(node ** first, node ** last, int index){
    if(isEmpty(*first)) return;
    if(index == 0){
        (*first) = (*first)->next;
        (*last)->next = (*first);
        return;
    }
    node * p = *first;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    if(p->next == *last){
        p->next = *first;
        (*last) = p;
        return;
    }
    p->next = p->next->next;
}


int main(){
    node * first =NULL;
    node * last = NULL;
    insert(&first, &last, 10, 0);
    display(first);
    insert(&first, &last, 10, 1);
    insert(&first, &last, 20, 2);
    insert(&first, &last, 30, 0);
    insert(&first, &last, 40, 3);
    insert(&first, &last, 60, 0);
    insert(&first, &last, 50, 0);
    insert(&first, &last, 70, 0);
    insert(&first, &last, 90, 0);
    display(first);
    delete(&first, &last, 2);
    display(first);
    return 0;
}
