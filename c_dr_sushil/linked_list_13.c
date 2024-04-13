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


bool isAbsDiff_1(Node * head){
    Node * p = head;

    while(p->next!=NULL){
        if(!(p->val- p->next->val ==1 || p->val- p->next->val == -1)){
            return false;
        }
        p=p->next;
    }
    return true;
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
    if(isAbsDiff_1(first)) printf("YES\n");
    else printf("NO\n");
    return 0;
}