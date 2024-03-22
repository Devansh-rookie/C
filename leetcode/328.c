/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head ==NULL || head->next== NULL||head ->next->next==NULL) return head;

    struct ListNode * p = head->next;
    struct ListNode * toLinkLL2 = head->next;
    struct ListNode * dummy =(struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    head->next = NULL; // disconnect from the LL-1
    struct ListNode * last = dummy->next;
    bool c=false;// or use bool here true for odd and even for faster calculations instead of int
    struct ListNode * pNext = p->next;
    struct ListNode * pPrev = NULL;
    while(pNext!=NULL){
        pNext = p->next;

        if(c== true){
            pPrev->next = pNext;
            p->next = last->next;
            last->next = p;
            last =p;
            c = !c;
            p = pNext;
            if(pNext!=NULL) pNext = pNext->next;
            continue;
        }

        c = !c;
        pPrev =p;
        p = pNext;
        if(pNext->next!=NULL) pNext = pNext->next;
    }

    last->next = toLinkLL2;
    return dummy->next;
}