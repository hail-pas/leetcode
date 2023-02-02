from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not all([l1, l2]):
            return l1 or l2

        l1_list = [l1.val]
        head = l1
        while(head.next):
            head = head.next
            l1_list.append(head.val)

        l2_list = [l2.val]
        head = l2
        while(head.next):
            head = head.next
            l2_list.append(head.val)

        l1_list.reverse()
        l2_list.reverse()

        if l1_list[0] == 0 or l2_list[0] == 0:
            return l2 if l1_list[0] == 0 else l1

        # 补 0
        if len(l1_list) > len(l2_list):
            l2_list = [0] * (len(l1_list) - len(l2_list)) + l2_list
        else:
            l1_list = [0] * (len(l2_list) - len(l1_list)) + l1_list

        result_list = []
        add_value = 0
        for i in range(len(l1_list) - 1, -1, -1):
            result_list.append((l1_list[i] + l2_list[i] + add_value) % 10)
            add_value = (l1_list[i] + l2_list[i] + add_value) // 10

        if add_value > 0:
            result_list.append(add_value)

        result = ListNode(result_list[0], None)

        head = result

        for i in result_list[1:]:
            temp = ListNode(i, None)
            head.next = temp
            head = temp
        return result


if __name__ == "__main__":
    l1 = ListNode(1, None)
    l2 = ListNode(0, None)

    head = l1
    for i in [8, 8, 1, 2]:
        temp = ListNode(i, None)
        head.next = temp
        head = temp

    head = l2
    for i in [6, 7, 9, 8, 4]:
        temp = ListNode(i, None)
        head.next = temp
        head = temp

    head = l1
    while head:
        print(head.val, sep=" ", end=" ")
        head = head.next

    print()

    head = l2
    while head:
        print(head.val, sep=" ", end=" ")
        head = head.next

    print()

    head = Solution().addTwoNumbers(l1, l2)
    while head:
        print(head.val, sep=" ", end=" ")
        head = head.next
    print()