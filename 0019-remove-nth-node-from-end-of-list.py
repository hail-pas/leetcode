# Definition for singly-linked list.
from typing import Optional


class ListNode:
    val: int
    next: "ListNode"

    def __init__(self, val=0, next: "ListNode" = None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # 空间换时间
        if not head:
            return head
        nodes = [head]
        current = head
        while current.next:
            current = current.next
            nodes.append(current)

        length = len(nodes)

        if length == 1:
            return None

        delete_index = length - n

        if delete_index == 0:
            head = head.next
        elif delete_index == length - 1:
            nodes[-2].next = None
        else:
            nodes[delete_index - 1].next = nodes[delete_index].next

        return head
