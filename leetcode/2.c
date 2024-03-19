/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL && l2==NULL) return NULL;
    else if(l1==NULL && l2!=NULL) return l2;
    else if(l1!=NULL && l2==NULL) return l1;

    struct ListNode * newHead=NULL;
    struct ListNode * last=NULL;
    struct ListNode * t= (struct ListNode*)malloc(sizeof(struct ListNode));

    int c=0;// c means carry here
    int value;

    newHead = t;
    last = t;
    value = l1->val +l2->val +c;
    t->val = value%10;
    c = value/10;
    t->next = NULL;
    l1=l1->next;
    l2=l2->next;

    while(l1!=NULL && l2!=NULL){
        struct ListNode * t2= (struct ListNode*)malloc(sizeof(struct ListNode));
        t2->next = NULL;
        value = l1->val +l2->val +c;
        t2->val = value%10;
        c = value/10;

        last->next = t2;
        last = t2;

        l1=l1->next;
        l2=l2->next;
    }

    while(l1!=NULL){
        struct ListNode * t2= (struct ListNode*)malloc(sizeof(struct ListNode));
        t2->next = NULL;
        value = l1->val +c;
        t2->val = value%10;
        c = value/10;

        last->next = t2;
        last = t2;

        l1=l1->next;
    }

    while(l2!=NULL){
        struct ListNode * t2= (struct ListNode*)malloc(sizeof(struct ListNode));
        t2->next = NULL;
        value = l2->val +c;
        t2->val = value%10;
        c = value/10;

        last->next = t2;
        last = t2;

        l2=l2->next;
    }

    if(c!=0){
        struct ListNode * t2= (struct ListNode*)malloc(sizeof(struct ListNode));
        t2->next = NULL;
        t2->val = c;
        last->next = t2;
        last = t2;
    }
    return newHead;
}