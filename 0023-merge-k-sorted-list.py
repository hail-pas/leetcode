from math import inf
from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self) -> str:
        return self.val

    def __repr__(self) -> str:
        return self.val

class Solution:

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # 基于合并两个有序连表的二分合并
        def merge2lists(h1,h2):
            h = r = ListNode(0)
            while h1 and h2:
                if h1.val < h2.val:
                    r.next = h1
                    h1 = h1.next
                    r = r.next
                else:
                    r.next = h2
                    h2 = h2.next
                    r = r.next
            r.next = h1 if h1 else h2
            return h.next

        def recur(l,r):
            if l > r: return None
            if l==r: return lists[l]
            mid = (l+r)//2
            lh = recur(l,mid)
            rh = recur(mid+1,r)
            return merge2lists(lh,rh)
        return recur(0,len(lists)-1)

    def _mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        # 暴力轮询
        current_nodes = [i for i in lists]
        dummy = ListNode()
        p = dummy
        while any(current_nodes):
            temp = None
            change_index = -1
            # print([i.val if i else None for i in current_nodes])
            for index, v in enumerate(current_nodes):
                if v and (temp is None or v.val < temp.val):
                    temp = v
                    change_index = index

            current_nodes[change_index] = current_nodes[change_index].next
            p.next = temp
            p = p.next

        return dummy.next


if __name__ == "__main__":
    node_values = [[1,4,5],[1,3,4],[2,6]]
    l1 = ListNode(1)
    p = l1
    for i in [4,5]:
        temp = ListNode(i)
        p.next = temp
        p = p.next

    l2 = ListNode(1)
    p = l2
    for i in [3, 4]:
        temp = ListNode(i)
        p.next = temp
        p = p.next

    l3 = ListNode(2)
    p = l3
    for i in [6]:
        temp = ListNode(i)
        p.next = temp
        p = p.next

    lists = [l1, l2, l3]

    result = Solution().mergeKLists(lists)

    while result:
        print(result.val, ", ")
        result = result.next
