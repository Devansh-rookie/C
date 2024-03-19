// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
// struct ListNode* deleteDuplicates(struct ListNode* p) {
//     struct ListNode* first= p;
//     // this is done because first is needed as p would be at the end while traversing so we would have to return the head of the list again
//     bool flag = false;
//     struct ListNode * previous=p;
//     if(p==NULL) return first;
//     while(p->next!=NULL){
//         if(p->val==(p->next)->val){
//             p->next = (p->next)->next;
//             flag = true;
//             continue;
//             // continue means we will not traverse the list here as we have found a duplicate and we will not traverse as long as we don't delete all the duplicate elements in the sorted linked list
//         }
//         if(flag){
//             previous->next= p->next;
//         }
//         flag = false;
//         previous = p;
//         p=p->next;
//     }
//     return first;
// }
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode * p = head->next;
    struct ListNode * pSave = NULL;
    struct ListNode * pTail = head;
    // this case has no sorted and same values on head
    bool first= true;
    while(p!=NULL){
        if(p->next != NULL &&p->val == p->next->val){
            pTail =p;
            p=p->next;
            continue;
        }

        if(!first) pSave->next = pTail;
        pSave = pTail;
        pTail = p;
        p= p->next;
        first = false;
    }
    return head;
}