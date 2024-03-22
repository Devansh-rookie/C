/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * reverseList(struct ListNode* head){
    struct ListNode * p= head;
    struct ListNode * q = NULL;
    struct ListNode * r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p=p->next;

        q->next = r;
    }
    return q;
}

// struct ListNode * middle(struct ListNode* head){
//     struct ListNode * slow= head;
//     struct ListNode * fast = head ->next->next;

//     while(fast!=NULL){
//         slow= slow->next;
//         if(fast->next == NULL){
//             fast = fast ->next;
//             continue;
//         }
//         fast= fast->next->next;
//     }
//     return slow;
// }

void reorderList(struct ListNode* head) {
    // reverse from the middle and insert that's all.
    if(head == NULL || head->next == NULL){
        return;
    }
    struct ListNode * fast = head->next->next;
    struct ListNode * midLeft = head;

    while(fast!=NULL){
        midLeft = midLeft->next;
        if(fast->next== NULL){
            fast = fast->next;
            continue;    
        }
        fast = fast->next->next;
    }
    // struct ListNode * lastLL1 = midLeft;
    struct ListNode * q = reverseList(midLeft->next);// q means the reversed pointer
    midLeft->next = NULL;
    struct ListNode * p = head;
    struct ListNode * qNext = q->next;
    struct ListNode * pNext = p->next;
    while(q!=NULL){
        p->next = q;
        q->next = pNext;
        p= pNext;
        if(pNext!=NULL) pNext = pNext->next;// can be a breaking point
        q = qNext;
        if(qNext != NULL) qNext = qNext->next;
    }
    return;
}