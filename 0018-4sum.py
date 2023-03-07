from typing import List

class Solution:
    def dfs(self):
        pass

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        # TODO: dfs
        length = len(nums)
        if length < 4:
            return []
        result = []
        return result

    def _fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        # 双重循环 + 双指针
        length = len(nums)
        if length < 4:
            return []
        nums.sort()

        result = []

        for i in range(0, length - 3):
            if i > 0 and nums[i] == nums[i-1]: continue
            if nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target: # 最小的四个数都大于目标值
                # 直接退出
                break
            if nums[i] + nums[length - 1] + nums[length - 2] + nums[length - 3] < target: # 最大的四个数都小于目标值
                # 继续增大当前循环最小值
                continue
            for j in range(i+1, length - 2):
                if j > i + 1 and nums[j] == nums[j-1]: continue
                if nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target:  # 最小的四个数都大于目标值
                    break
                if nums[i] + nums[j] + nums[length - 1] + nums[length - 2] < target: # 最大的四个数都小于目标值
                    # 继续增大当前循环最小值
                    continue
                k = j + 1
                l = length - 1
                while k < l:
                    if nums[i] + nums[j] + nums[k] + nums[l] > target:
                        l -= 1
                    elif nums[i] + nums[j] + nums[k] + nums[l] < target:
                        k += 1
                    else:
                        result.append([nums[i], nums[j], nums[k], nums[l]])
                        while k < l and nums[k] == nums[k+1]: # 去重，注意外层循环的结束条件
                            k += 1
                        k += 1
                        while k < l and nums[l] == nums[l - 1]:
                            l -= 1
                        l -= 1

        return result


if __name__ == "__main__":
    nums = [-2,-1,-1,1,1,2,2]
    target = 0
    print(Solution().fourSum(nums, target))
