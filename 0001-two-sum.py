from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashtable = {}
        result = []
        for index, value in enumerate(nums):
            if (target - value) in  hashtable:
                result = [hashtable.get(target - value), index]
                break
            hashtable[value] = index
        return result
