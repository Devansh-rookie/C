/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int count(struct ListNode * p){
    int c=0;
    while(p!=NULL){
        p=p->next;
        c++;
    }
    return c;
}
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode * pBefore=NULL;
    struct ListNode * p=head;
    // when the value is not at first for now
    int c= count(p);
    if (c==0||c==1){
        return head;
    }
    while(p!=NULL && p->val<x ){// Lazy Evaluation
        pBefore = p;
        p=p->next;
    }
    if(p!=head){
        struct ListNode * new=NULL;
        new = pBefore;
        while(p!=NULL){
            if(p->val>=x){
                new = p;
                p=p->next;
                continue;
            }
            struct ListNode * t=p;

            new->next = t->next;
            t->next= pBefore->next;
            pBefore->next = t;
            pBefore = t;
            p=p->next;
        }
        return head;
    }
    // now as we have already returned the value in if statement this Code Block will work as an else statement
    bool flag = true; // this will tell if the element is the first one or not, to be changed as the first element to be changed would be assigned the head
    struct ListNode * new=NULL;
    new = pBefore;

    while(p!=NULL){
        if(p->val>=x){
            new = p;
            p=p->next;
            continue;
        }
        // here p->val is smaller than x, as we have used a continue keyword in the if statement
        if(flag){
            struct ListNode * t=p;
            new->next =t->next;
            t->next=head;
            head = t;
            p=p->next;
            pBefore = t;
            flag = false;
            continue;
        }
        struct ListNode * t=p;

        new->next = t->next;
        t->next= pBefore->next;
        pBefore->next = t;
        pBefore = t;
        p=p->next;
    }
    return head;
}