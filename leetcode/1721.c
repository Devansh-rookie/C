/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int count(struct ListNode* p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}


struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* p= head;
    int i= 1;
    // lets try both by Swapping the Nodes of the Linked List and the Values
    int n= count(head);
    if(n==0||n==1) return head;
    while(p!=NULL && i<k){
        p=p->next;
        i++;
    }
    struct ListNode* temp1 = p;
    p= head;
    i=1;

    while(p!=NULL && i<=n-k){
        p=p->next;
        i++;
    }
    struct ListNode* temp2 = p;
    int temp = temp1->val;
    temp1->val = temp2->val;
    temp2->val = temp;
    return head;
}
