"""
倒序存储则可以直接从个位数相加，长度不一致的情况高位补0，
最后需要判断结果最高位是否有进位，有则加一个
"""


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


def add_two_numbers(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    answer = ListNode(0)
    point = answer
    carry = 0
    while l1 or l2:
        x = l1.val if l1 else 0
        y = l2.val if l2 else 0
        sum = x + y + carry
        if sum > 9:
            carry = 1
            value = sum - 10
        else:
            carry = 0
            value = sum
        point.next = ListNode(value)
        point = point.next
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
    if carry > 0:
        point.next = ListNode(carry)
    return answer.next
