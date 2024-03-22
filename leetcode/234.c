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

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode * p= head;
    struct ListNode * q= NULL;
    struct ListNode * r= NULL;
    if(p==NULL||p->next==NULL){
        return head;
    }
    while(p!=NULL){
        r = q;
        q = p;
        p=p->next;
        
        q->next = r;
    }
    head = q;
    return head;
}


bool isPalindrome(struct ListNode* head) {
    if(head->next == NULL) return true;

    struct ListNode * p = head;
    
    struct ListNode * slow = head;
    struct ListNode * fast = head->next->next;

    while(fast!= NULL){
        slow = slow->next;
        if(fast->next !=NULL) fast = fast->next->next;
        else if(fast->next==NULL) fast = fast->next;
    }
    struct ListNode * q = reverseList(slow->next);
    while(q!=NULL){ // as this will bypass the middle element if we have an odd Lengthed Linked List, as the number of operations would be n/2 instead of the number of terms in the first partition that is n/2 if its odd Lengthed
        if(q->val != p->val) return false;
        p = p->next;
        q=q->next;
    }
    return true;
}

