#include <stdbool.h>
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) 
        return head;

    struct ListNode *dummy;
    dummy->next = head;
    struct ListNode *curr = head->next;
    head->next = NULL;

    while (curr != NULL) {
        struct ListNode *prev = dummy;
        struct ListNode *next = curr->next;

        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;

        curr = next;
    }

    return dummy->next;
}
