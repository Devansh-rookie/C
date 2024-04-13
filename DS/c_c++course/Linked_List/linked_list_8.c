#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int val;
    struct Node* next;
}Node;

void insertLast(Node ** first,Node **last,int val){
    Node * t = (Node*)malloc(sizeof(Node));
    t->val = val;
    t->next = NULL;
    if((*first)==NULL){
        (*first)= t;
        (*last)= t;
        return;
    }
    (*last)->next = t;
    (*last) = t;
}

// Node * removeDuplicates(Node * head){
//     Node * dummy = (Node *)malloc(sizeof(Node));
//     dummy ->next = head;
//     Node * p = head;
//     Node * pSlow = dummy;
//     Node * pTail = dummy;
//     while (pSlow->next!=NULL)
//     {
//         Node * pTail = pSlow;
//         while (p!=NULL)
//         {
//             if(p!=pSlow->next && p->val == pSlow->next->val){
//                 pTail->next = pTail->next->next;
//                 continue;
//             }
//             pTail = pTail->next;
//             p=p->next;
//         }
//         pSlow=pSlow->next;
//     }
//     return dummy->next;
// }

Node * removeDuplicatesM2(Node * head){
    Node * dummy = (Node * )malloc(sizeof(Node));
    dummy ->next = NULL;
    Node * last= NULL;
    Node * p = head;
    Node * pFast = head;
    bool repeated = false;
    while (p!=NULL)
    {
        pFast = head;
        while(pFast!=NULL){
            if(p!=pFast && pFast->val == p->val){
                repeated = true;
            }
            pFast = pFast->next;
        }
        if(!repeated){
            insertLast(&(dummy->next), & last,p->val);
        }
        repeated = false;
        p=p->next;
    }
    return dummy->next;
}

void display(Node *p){
    printf("\n");
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}

int main(){
    Node * first=NULL; Node * last=NULL;
    insertLast(&first,&last, 15);
    insertLast(&first,&last, 17);
    insertLast(&first,&last, 15);
    insertLast(&first,&last, 78);
    insertLast(&first,&last, 23);
    insertLast(&first,&last, 15);
    insertLast(&first,&last, 23);
    insertLast(&first,&last, 29);
    insertLast(&first,&last, 70);

    display(first);
    display(removeDuplicatesM2(first));

    return 0;
}
