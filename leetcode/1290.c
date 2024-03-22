/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<math.h>

int count(struct ListNode* p){
    int c=0;
    while(p!=NULL){
        p=p->next;
        c++;
    }
    return c;
}

int getDecimalValue(struct ListNode* head) {
    int ans =0;
    struct ListNode * p= head;
    int n= count(head)-1; // n is the place from where to start from in 2's powers
    while(p!=NULL){
        ans+= pow(2,n)*p->val;
        n--;
        p=p->next;
    }
    return ans;
}