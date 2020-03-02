"""
空间换时间的做法， O(n)
hash存储遍历过的值
"""


def two_sum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    nums_map = {}  # 缓存 值 - 脚标
    for i, num in enumerate(nums):
        another_num = target - num
        if another_num in nums_map:
            return [i, nums_map[another_num]]
        nums_map[num] = i
    return None
