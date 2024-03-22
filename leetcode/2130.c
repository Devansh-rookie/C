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
        p=p->next;
        c++;
    }
    return c;
}

struct ListNode * reverse(struct ListNode * head){
    struct ListNode * p = head;
    struct ListNode * q = NULL;
    struct ListNode * r = NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next = r;
    }
    return q;
}

int pairSum(struct ListNode* head) {
    // struct ListNode* p = head;
    // int k= count(head);//countToFinish
    // int n= k;
    // int max=0;
    // while(k>n/2){
    //     int i=0;
    //     while(i<k-1){
    //         p=p->next;
    //         i++;
    //     }
    //     i=0;
    //     int t1= p->val;
    //     p=head;
    //     while(i<n-k){
    //         p=p->next;
    //         i++;
    //     }
    //     int t2= p->val;
    //     p=head;
    //     k--;
    //     if(t1+t2>max) max = t1+t2;
    // }

    if(head->next->next==NULL){
        return head->val+ head->next->val;
    }
    struct ListNode *pTail = NULL;
    struct ListNode* p = head;
    struct ListNode* pFast = head;
    while(pFast!=NULL && pFast->next!=NULL){// I did this wrong p has to be on he right of middle and pTail before it then disconnect it using pTail->next = NULL and reverse everything ahead of p
        pTail = p;
        p=p->next;
        pFast = pFast->next->next;
    }
    // p=p->next;
    pTail->next = NULL;
    struct ListNode* q= reverse(p);
    p = head;
    int max=0;
    while(p!=NULL&& q!=NULL){
        int sum = p->val+q->val;
        if(sum>max) max =sum;
        p=p->next;
        q = q->next;
    }

    return max;
}