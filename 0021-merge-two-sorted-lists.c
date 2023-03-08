#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    struct ListNode *p = dummy;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            p->next = list1;
            list1 = list1->next;
        }else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    p->next = list1 == NULL ? list2: list1;
    return dummy->next;
}
