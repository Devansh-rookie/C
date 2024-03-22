/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode * p= list1;
    struct ListNode * q= list2;
    for(int i=0;i<a-1;i++) p=p->next;
    struct ListNode* toB = p;
    for(int i=0;i<=b-a;i++) toB=toB->next;
    p->next = list2;
    while(q->next!=NULL) q=q->next;
    q->next = toB->next;
    free(toB);
    return list1;
}