/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    if(head == NULL|| head->next==NULL) return head;
    
    struct ListNode * slow = head;
    struct ListNode * fast = head->next->next;
    int c=0;

    while(fast!= NULL){
        slow = slow->next;
        if(fast->next !=NULL){
            fast = fast->next->next;
            c=0;// represents even number in the length of the linked list
        }
        else if(fast->next==NULL){
            fast = fast->next;
            c=1;// represents Odd number in the length of the Linked List
        }
    }

    if(c==1) return slow;
    return slow->next;
}