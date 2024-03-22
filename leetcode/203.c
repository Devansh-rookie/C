/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* p = head;
    
    if(head == NULL) return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy ->next = head;
    p= dummy;
    while(p->next!=NULL){
        if((p->next)->val == val){
            p->next = p->next->next;
            continue;
        }
        // pTail = p;
        p=p->next;
    }
    return dummy->next;
}