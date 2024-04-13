// Roll No. : 123110034 (MC-A-03)(Mathematics and Computing)
// Name : Devansh

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node * next;
}Node;

int count(Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void display(Node * p){
    printf("\n");
    while(p!=NULL){
        printf("%d ", p->val);
        p=p->next;
    }
    printf("\n");
}

Node * partition(Node * head, int x){
    Node * pBefore = NULL;
    Node * p = head;
    
    int c = count(p);
    if(c==0||c==1)return head;
    while(p!=NULL &&p->val<x){
        pBefore = p;
        p=p->next;
    }
    if(p!=head){
        Node * New = pBefore;
        while(p!=NULL){
            if(p->val>=x){
                New = p;
                p=p->next;
                continue;
            }
            Node * t = p;
            
            New->next = t->next;
            t->next = pBefore->next;
            pBefore->next = t;
            pBefore=t;
            p=p->next;
        }
        return head;
    }
    bool flag = true;
    Node * New = pBefore;
    
    while(p!=NULL){
        if(p->val>=x){
            New =p;
            p=p->next;
            continue;
        }
        if(flag){
            Node *t = p;
            New->next = t->next;
            pBefore =t;
            t->next = head;
            head = t;
            flag=false;
            p=p->next;
            continue;
        }
        
        Node * t = p;
        New->next = t->next;
        t->next = pBefore->next;
        pBefore->next = t;
        pBefore = t;
        p=p->next;
    }
    return head;
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
    int x;
    display(first);
    printf("\nWhat to partition about: ");
    scanf("%d",&x);
    Node * q = partition(first, x);
    display(q);
    return 0;
}



