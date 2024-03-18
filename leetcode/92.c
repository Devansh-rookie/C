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
        c++;
        p=p->next;
    }
    return c;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode * pLeft = head;
    struct ListNode * pRight = head;
    int c= count(head);
    if(c==0|| c==1) return head;
    if(left==right) return head;

    if(right - left == 1 && left == 1){
        for(int i=0;i<left -2;i++, pLeft=pLeft->next);
        pRight = pLeft ->next;
        pLeft->next = pRight->next;
        pRight ->next = pLeft;
        return pRight;
    }

    if(left == 1){
        struct ListNode * p = NULL;struct ListNode * q = NULL;struct ListNode * r = NULL;
        for(int i=0;i<right ;i++, pRight=pRight->next);
        p = pLeft;
        q= NULL;
        r= NULL;
        while(p!=pRight){
            r = q;
            q= p;
            p=p->next;
            q->next = r;
        }
        pLeft->next = pRight;
        head = q;
        return head;
    }

    for(int i=0;i<left -2;i++, pLeft=pLeft->next);
    for(int i=0;i<right ;i++, pRight=pRight->next);

    struct ListNode * p = NULL;struct ListNode * q = NULL;struct ListNode * r = NULL;
    if(pLeft->next->next !=NULL) p= pLeft->next->next;
    if(pLeft->next !=NULL) q= pLeft->next;
    r= pLeft;

    q -> next = pRight;

    while(p!=pRight){
        r = q;
        q= p;
        p=p->next;

        q->next = r;
    }
    pLeft->next = q;

    return head;
}