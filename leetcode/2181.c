/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode * dummy= (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * last;
    struct ListNode * p = head;
    int sum =0;
    last = dummy;
    last->next = NULL;

    while(p->next!=NULL){
        if((p->next)->val != 0){
            sum+= (p->next)->val;
        }
        else if((p->next)->val == 0){
            struct ListNode * t= (struct ListNode *)malloc(sizeof(struct ListNode));
            last->next = t;
            t->val = sum;
            t->next = NULL;
            last = t;
            sum=0;
        }
        if(p->next!=NULL)p=p->next;
    }

    return dummy->next;
}