/**
 * Definition for singly-linked list.
 */
#include <iostream>

// class ListNode {
//     public: int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result = nullptr, *head = nullptr;
        int add_value = 0, operate_value = 0;
        while (l1 or l2) {
            operate_value = 0;
            if (l1) {
                operate_value += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                operate_value += l2->val;
                l2 = l2->next;
            }
            auto temp = new ListNode((operate_value + add_value) % 10);
            add_value = (operate_value + add_value) / 10;
            if (nullptr == result) {
                // result = (ListNode *)std::malloc(sizeof(ListNode));
                result = temp;
                head = result;
            }else {
                head->next = temp;
                head = head->next;
            }
        }
        if (add_value > 0) {
            auto temp = new ListNode(add_value);
            head->next = temp;
        }
        return result;
    }
};

void print(ListNode * ln) {
    std::cout<<"ListNode: ";
    while (nullptr != ln) {
        std::cout<<ln->val<<" ";
        ln = ln->next;
    }
    std::cout<<std::endl;
}

ListNode * create(ListNode * ln, int *nums, int size){
    ListNode * head = nullptr;
    for (int i=0; i<size; i++) {
        auto temp = new ListNode(*(nums+i));
        if (nullptr == ln) {
            ln = temp;
            head = ln;
        }else {
            head->next = temp;
            head = head->next;
        }
    }
    return ln;
}

int main(int argc, char const *argv[]) {
    ListNode * l1 = nullptr, *l2 = nullptr, *head = nullptr;

    // int nums1[] = {2, 4, 3};
    int nums1[] = {9,9,9,9,9,9,9};

    l1 = create(l1, nums1, sizeof(nums1)/sizeof(int));

    // int nums2[] = {5, 6, 4};
    int nums2[] = {9,9,9,9};

    l2 = create(l2, nums2, sizeof(nums2)/sizeof(int));

    print(l1);
    print(l2);
    print(Solution().addTwoNumbers(l1, l2));
    return 0;
}