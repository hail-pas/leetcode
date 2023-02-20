from typing import List

class Solution:

    def maxArea(self, height: List[int]) -> int:
        # right_index - left_index and min(height[right_index], height[left_index])
        # s = (right_index - left_index) * min(height[right_index], height[left_index])
        # 假设初始状态为以两端的板
        # 两端的板向内移动 无论如何都导致 底边长度减小，则只能考虑高度变化
        # 1. 长板移动
        #       1.1 长板依旧为长板 -> 高度不变、底边变短 -> 面积减小   ===  忽略
        #       1.2 长板变短板 -> 高度变低、底边变短 -> 面积减少   ===  忽略
        # 2. 短板移动
        #       2.2 短板变长板 -> 高度变高、底边变短 -> 面积可能增大
        #       2.3 短板依旧为短板:
        #           2.3.1 高度于低原来值 -> 高度变低、底边变短 -> 面积减少   ===  忽略
        #           2.3.2 高度高于原来值 -> 高度变高、底边变短 -> 面积可能增大
        result = 0
        left_index = 0
        right_index = len(height) - 1
        while left_index < right_index:
            temp_h = min(height[left_index], height[right_index])
            temp_s = (right_index - left_index) * min(height[left_index], height[right_index])
            if temp_s > result:
                result = temp_s
            # 忽略高度于低原来值
            while height[left_index] <= temp_h and left_index < right_index:
                left_index += 1
            while height[right_index] <= temp_h and left_index < right_index:
                right_index -=1
        return result


    def _maxArea(self, height: List[int]) -> int:
        # 暴力循环
        # 坐标差大 且 最小高度尽量大
        result = 0
        for right_index in range(len(height)):
            for left_index in range(0, right_index):
                h = min(height[right_index], height[left_index])
                temp = h * (right_index - left_index)
                if temp > result:
                    result = temp
        return result

if __name__ == "__main__":
    height = [1,8,6,2,5,4,8,3,7]
    print(Solution().maxArea(height))
