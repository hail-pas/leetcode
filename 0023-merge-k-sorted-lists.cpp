#include <vector>
#include <iostream>
/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode * l1, ListNode * l2){
        if ((!l1) || (!l2)) return l1 ? l1 : l2;
        ListNode * dummy = new ListNode();
        ListNode * p = dummy;
        while (l1 and l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            }else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = (l1 ? l1 : l2);
        return dummy->next;
    }
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // ListNode *p = nullptr;
        // for (auto i: lists) {
        //     p = mergeTwoLists(p, i);
        // }
        // return p;
        return binMerge(lists, 0, lists.size() - 1);
    }

    ListNode * binMerge(std::vector<ListNode*>& lists, int start, int end){
        if (start > end) {
            return  nullptr;
        }
        if (start == end) {
            return lists[start];
        }
        int mid = (start + end) >> 1;
        return mergeTwoLists(binMerge(lists, start, mid), binMerge(lists, mid + 1, end));
    }
};
