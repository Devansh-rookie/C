/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* giveMiddleLeft(struct ListNode* p){
    if(p==NULL|| p->next == NULL||p->next->next== NULL) return p;
    struct ListNode* slowTail = NULL;
    struct ListNode* slow = p;
    struct ListNode* fast = p->next->next;
    bool odd;
    while(fast!=NULL){// will give the left of middle each time as slow
        slowTail = slow;
        slow = slow->next;
        if(fast->next!=NULL){
            fast = fast->next->next;
            odd = false;
        }
        else if(fast->next == NULL){
            fast = fast->next;
            odd = true;
        }
    }
    if(odd) return slowTail;
    return slow;
}

struct ListNode* deleteMiddle(struct ListNode* head) {
    if(head== NULL|| head->next == NULL) return NULL;
    struct ListNode* p = head;
    struct ListNode* mid = giveMiddleLeft(p);
    mid->next= mid->next->next;
    return head;
}