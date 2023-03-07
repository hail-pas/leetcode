/**
 * Definition for singly-linked list.
 */
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = head;
    struct ListNode * first = head;
    struct ListNode * second = dummy;
    for (int i = 0; i < n; i++) {
        first = first->next;
    }
    while (first) {
        second = second->next;
        first = first->next;
    }
    second->next = second->next->next;
    struct ListNode * result = dummy->next;
    free(dummy);
    return result;
}
