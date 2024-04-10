#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}node;

bool isEmpty(node * first){
    if(first == NULL){
        printf("Underflow\n");
        return true;
    }
    return false;
}

node * insertAtLast(node ** first, node ** last, int val){// enqueue
    node * t = (node *)malloc(sizeof(node));
    t->val = val;
    t->next = NULL;
    if(isEmpty(*first)){
        (*first)= t;
        (*last)= t;
        return t;
    }
    (*last)->next = t;
    (*last) = t;
    return (*first);
}

void display(node * first){
    printf("\n");
    while(first != NULL){
        printf("%d ", first->val);
        first = first->next;
    }
    printf("\n");
}

node * dequeue(node ** first){
    if(isEmpty(*first)) return NULL;
    node * t = (*first);
    (*first) = (*first)->next;
    // free(t);
    return (t);
}

node * peek(node * first){
    if(isEmpty(first)) return NULL;
    return (first);
}

int main(){
    node * first=NULL; node* rear = NULL; 
    int ch;
    node * t;
    while (true)
    {
        printf("\n");
        printf("Give your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("What to Enqueue: ");
            int a;
            scanf("%d",&a);
            insertAtLast(&first,&rear,a);
            break;
        case 2:
            t = dequeue(&first);
            if(t==NULL) break;
            printf("\n%d\n", t->val);
            break;
        case 3:
            t = peek(first);
            if(t==NULL) break;
            printf("\n%d\n",t->val);
            break;
        case 4:
            display(first);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Enter a valid value\n");
            break;
        }
    }
    return 0;
}
