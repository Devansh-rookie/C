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

struct ListNode* rotateRight(struct ListNode* head, int k) {
    int n= count(head);
    if(n==0||n==1) return head;

    struct ListNode * p= head;
    struct ListNode * pTail= NULL;
    struct ListNode * pTailTail= NULL;
    int numTimesRotate = k%n;

    for(int i=1;i<=numTimesRotate;i++){// or 0 to < numTimesRotate
        while(p!=NULL){
            pTailTail = pTail;
            pTail = p;
            p=p->next;
        }
        pTail->next = head;
        pTailTail->next = p;// or use NULL here instead of p 

        head = pTail;
        p= head;
    }

    return head;
}