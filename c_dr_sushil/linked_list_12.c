#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node * next;
}Node;


void display(Node * p){
    printf("\n");
    while(p!=NULL){
        printf("%d ", p->val);
        p=p->next;
    }
    printf("\n");
}

void insertLast(Node ** first, Node ** last , int val){
    Node * t = (Node *)malloc(sizeof(Node));
    t->val = val;
    t->next = NULL;
    if(*first == NULL){
        *first = t;
        *last = t;
        return;
    }
    (*last)->next = t;
    *last = t;
    
    return;
}


Node * count_surpassers(Node * head){
    Node * p = head;
    while(p->next!=NULL){
        Node * q = p->next;
        int c=0;
        while (q!=NULL)
        {
            if(q->val>p->val){
                c++;
            }
            q=q->next;
        }
        p->val = c;
        p=p->next;
    }
    p->val =0;// last value should be 0
    return head;
}


int main(){
    Node *first=NULL;
    Node * last = NULL;
    int ch;
    while(true){
        printf("Enter the element (0 to exit): ");
        scanf("%d",&ch);
        if(ch==0) break;
        insertLast(&first,&last,ch);
    }
    display(first);
    display(count_surpassers(first));
    return 0;
}