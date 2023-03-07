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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 双指针， 两个指针间隔 n， 将后一个指针指向尾元素，另一个指针则指向被删除元素，为了更方便可以设置 dummy 节点
        ListNode* dummy = new ListNode(0, head);
        ListNode * first = head, *second = dummy;
        for (int i = 0; i < n; i++) {
            first = first->next;
        }
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
