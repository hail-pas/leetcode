#include <stdlib.h>
/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode * mergeTwoLists(struct ListNode * l1, struct ListNode * l2){
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * p = dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = l1 ? l1 : l2;
    return dummy->next;
}

struct ListNode * merge(struct ListNode** lists, int start, int end){
    if (start > end) {
        return NULL;
    }
    if (start == end) {
        return *(lists + start);
    }
    int mid = (start + end) >> 1;
    return mergeTwoLists(merge(lists, start, mid), merge(lists, mid + 1, end));
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    return merge(lists, 0, listsSize - 1);
}
