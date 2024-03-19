#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int val;
    struct Node * next;
}Node;


Node * insertionSort(Node * head){
    if(head==NULL || head->next==NULL) return head;

    Node * dummy = (Node*) malloc(sizeof(Node));

    dummy->next= head;

    Node * p = head->next;// this is because we would take the head in the Linked List 1 and then we would start traversing and comparing it to the other LL starting from head->next, compare with each and if the value in the LL2 is smaller insert it after new. new represents the pointer after which we would find a value larger the new->next so the p is to be inserted after new and before new->next;

    head->next= NULL;// new LL with the Linked List
    Node* pNext= p->next;// this is to store p->next as we would have to change p's links with p->next;
    Node * new= dummy;// this is dummy as we always have to compare using new->next and not new it self

    while(p!=NULL){
        new = dummy;
        pNext=p->next;
        //LL1 is the partially sorted sub list
        while (new->next!=NULL && (new->next)->val< p->val)// also terminate if new reached the end of the LL1 as it means that the p's value if the largest yet so insert in the end new->next jab jab chhota move to new->next until end else break if new->next is bigger
        {
            new=new->next;
        }
        
        p->next = new->next;
        new->next=p;

        p=pNext; // as p's links have changed
        if(pNext!=NULL) pNext=pNext->next;
    }

    head = dummy->next;
    free(dummy);
    return head;
}


void insertAtLast(Node ** p,Node ** last,int num){
    Node * t = (Node *)malloc(sizeof(Node));
    t->val = num;
    t->next = NULL;
    if(*p ==NULL && * last == NULL){
        (*p)= t;
        (*last)= t;
    }
    else{
        (*last)->next = t;
        (*last)= t;
    }
}

void display(Node * p){
    printf("\n");
    while(p!=NULL){
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}


int main(){
    Node * head1=NULL, *last1=NULL;

    insertAtLast(&head1,&last1,-10);
    insertAtLast(&head1,&last1,100);
    insertAtLast(&head1,&last1,30);
    insertAtLast(&head1,&last1, 70);
    insertAtLast(&head1,&last1,-90);

    display(head1);

    Node* p = insertionSort(head1);

    display(p);
    return 0;
}
