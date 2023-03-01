from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # 基于三层遍历
        # 去重的关键在于排序，且跳过遍历层级里值相等的元素
        # 减少遍历的关键在于双指针，确定 a 的情况， b 增 则 c 减
        result = []
        length = len(nums)
        if not length:
            return result
        nums.sort()
        for i in range(length - 2):
            if nums[i] > 0: break
            # 保证和上一次的枚举数不同, 忽略同层级相同的元素
            if i >= 1 and nums[i] == nums[i-1]:
                continue
            # j 变大的同时必须要满足 k 减小，即 post_j 对应的 k 一定小于 pre_j 对应的 min(k)
            # 确定 i、j 的情况下的 k
            k = length - 1
            target = -nums[i]
            for j in range(i+1, length -1):
                # 保证和上一次的枚举数不同
                if j > i + 1 and nums[j] == nums[j -1]:
                    continue
                # 获取 i，j 确定情况下的 k
                # 只有在 j<k 且 nums[j] + nums[k] = target 的情况下满足
                while j < k and nums[j] + nums[k] > target:
                    # k左移即值减小
                    k -= 1

                if j == k:
                    # 元素重复
                    # j 会继续增大，而 k 会减少，不存在 a+b+c = 0，且 b < c. 会导致重复
                    break

                if nums[j] + nums[k] == target:
                    result.append([nums[i], nums[j], nums[k]])

        return result

if __name__ == "__main__":
    print(Solution().threeSum([-1, -1, -1, -1, 0, 1, 1, 1]))
