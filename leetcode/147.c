/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL|| head->next == NULL) return head;

// This lead to a lot of fuck ups
//     struct ListNode * pFast = head->next;
//     struct ListNode * p = head;
//     struct ListNode * pTail = NULL;

//     struct ListNode * new = head;
//     struct ListNode * newTail = NULL;

//     bool changed_head = false;
//     while(pFast!=NULL){

//         while(new!=p && new->val < p->val){
//             newTail = new;
//             new= new->next;
//         }
//         if(new->val >= p->val && p!=head){
//             if(new==head){
//                 struct ListNode * t = p;
//                 // if(pTail!=NULL) pTail->next = t->next;//can be a breaking point 
//                 pTail->next = t->next;
//                 // if(pTail == NULL) new->next = t->next;//can be a breaking point
//                 t->next = new;
//                 head = t;
//                 changed_head = true;
//             }
//             else{
//                 struct ListNode * t = p;

//                 pTail->next = t->next;
//                 newTail->next = t;
//                 t->next = new;
//             }
//         }

// // use this method to traversing whenever possible it would reduce the Number of segmentation faults/ NULL Value accessing, Error things.
//         // pTail = p;
//         if(!changed_head){
//             pTail = p;
//             changed_head = false;
//         }
//         else{
//             pTail=pTail->next;
//             changed_head = false;
//         }
//         p= pFast;
//         pFast=pFast->next;

//         new = head;
//         newTail = NULL;
//     }
    struct ListNode * dummy= (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next= head;
    struct ListNode * p= head->next;

    head ->next = NULL;
    
    struct ListNode * newTraverse= dummy;// it basically means a new half of linked list
    struct ListNode * pNext= p->next; // p and pNext are in the original Linked List from where we are getting the numbers/data and adding in the LL with the other pointer that is dummy->next basically.

    while(p!=NULL){
        newTraverse=dummy;// important line: to reset the newTraverse each time to the dummy, like in each iteration
        pNext = p->next;// to make pNext p->next in each iteration as links between p and p->next have to be changed

        while(newTraverse->next != NULL && newTraverse->next->val < p->val){
            newTraverse = newTraverse->next;
        }

        p->next=newTraverse->next;

        newTraverse->next = p;

        p=pNext;
        if(pNext!=NULL) pNext = pNext->next;
    }

    head = dummy->next;
    free(dummy);
    return head;
}
