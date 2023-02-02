/**
 * Definition for singly-linked list.
*/
#include "stdio.h"
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void print(struct ListNode * ln) {
    printf("ListNode: ");
    while (ln) {
        printf("%d  ", ln->val);
        ln = ln->next;
    }
    printf("\n");
}

struct ListNode * create(struct ListNode * ln, int *nums, int size){
    struct ListNode * head = NULL;
    for (int i=0; i<size; i++) {
        struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (!ln) {
            ln = temp;
            head = ln;
        }else {
            head->next = temp;
            head = head->next;
        }
    }
    return ln;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * result = NULL, *head = NULL;
        int add_value = 0, operate_value = 0;
        while (l1 || l2) {
            operate_value = 0;
            if (l1) {
                operate_value += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                operate_value += l2->val;
                l2 = l2->next;
            }
            struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val = (operate_value + add_value) % 10;
            add_value = (operate_value + add_value) / 10;
            if (!result) {
                // result = (ListNode *)std::malloc(sizeof(ListNode));
                result = temp;
                head = result;
            }else {
                head->next = temp;
                head = head->next;
            }
        }
        if (add_value > 0) {
            struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val = add_value;
            head->next = temp;
        }
        return result;
}