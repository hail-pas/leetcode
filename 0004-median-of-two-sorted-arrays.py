from typing import List

class Solution:

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 二分 切分  O(log(min(m, n)))  &  O(1)
        # 0 =< i <= m, 0 =< j <= n
        # 边界： i = 0, i = m; j = 0, j = m
        # 切分成左右两份, nums1[i - 1] <= nums2[j],  nums2[j - 1] <= nums1[i]
        # i,j 关系： j = (m + n + 1) // 2 - i, 两边切分, 整除兼容了奇偶
        # 且 max(nums1[i-1], nums2[j - 1]) <= min(nums1[i], nums2[j]) -> nums1[i-1] <= nums2[j] and nums2[j - 1] <= nums1[i]

        m = len(nums1)
        n = len(nums2)
        if m > n:
            return self.findMedianSortedArrays(nums2, nums1)

        i_min = 0
        i_max = m

        while i_min <= i_max:
            i = (i_min + i_max) // 2
            j = (m + n + 1) // 2 - i  # 奇数的情况下左边会比右边多一个数
            # 切分处 nums1 左部分最大值 > nums2 右部分最小值, i 左移, j 右移, 直到 nums1[i-1] <= nums2[j]
            if i != 0 and j != n and nums1[i - 1] > nums2[j]:
                i_max = i - 1
            # 切分处 num1 左部分最大值 < nums2 右部分最小值, i右移动, j 左移, 直到 nums2[j - 1] <= nums1[i]
            elif j != 0 and i != m and nums2[j - 1] > nums1[i]:
                i_min = i + 1
            else:
                max_left = 0
                if i == 0:
                    max_left = nums2[j - 1]
                elif j == 0:
                    max_left = nums1[i - 1]
                else:
                    max_left = max(nums1[i-1], nums2[j-1])

                if (m + n) % 2 != 0: # 奇数直接返回左部最大值
                    return max_left

                min_right = 0
                if i == m:
                    min_right = nums2[j]
                elif j == n:
                    min_right = nums1[i]
                else:
                    min_right = min(nums1[i], nums2[j])

                return (max_left + min_right) / 2  # 偶数的情况

        return 0



    def ____findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 二分找 k 小数, O(log(m + n))  & O(1)
        total_length = len(nums1) + len(nums2)
        mid_right_index = total_length // 2
        mid_left_index = mid_right_index - 1 if total_length % 2 == 0 and mid_right_index >= 1 else mid_right_index
        if mid_left_index == mid_right_index:
            return self.get_kth(nums1, 0, len(nums1) - 1, nums2, 0, len(nums2) - 1, mid_left_index + 1)
        return (self.get_kth(nums1, 0, len(nums1) - 1, nums2, 0, len(nums2) - 1, mid_left_index + 1) + self.get_kth(nums1, 0, len(nums1) - 1, nums2, 0, len(nums2) - 1, mid_right_index + 1)) / 2

    def get_kth(self, nums1: List[int], start1: int, end1: int, nums2: List[int], start2: int, end2: int, k: int):
        # 递归获取第 k 小数
        len1 = end1 - start1 + 1
        len2 = end2 - start2 + 1
        if len1 > len2: return self.get_kth(nums2, start2, end2, nums1, start1, end1, k)

        # 递归结束条件只剩一个数组
        if len1 == 0: return nums2[start2 + k - 1]

        # 递归结束条件最小的
        if k == 1: return min(nums1[start1], nums2[start2])

        i = start1 + min(len1, k//2) - 1
        j = start2 + min(len2, k//2) - 1

        # 尾递归, 排除小的部分
        if nums1[i] > nums2[j]:
            return self.get_kth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1))
        else:
            return self.get_kth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1))


    def ___findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 遍历找 k 小数 O(m+n)  &  O(1)
        total_length = len(nums1) + len(nums2)
        mid_right_index = total_length // 2
        mid_left_index = mid_right_index - 1 if total_length % 2 == 0 and mid_right_index >= 1 else mid_right_index
        mid_left_value = mid_right_value = 0
        i = j = 0
        for index in range(total_length):
            if i == len(nums1):
                value = nums2[j]
                j += 1
            elif j == len(nums2):
                value = nums1[i]
                i += 1
            else:
                if nums1[i] < nums2[j]:
                    value = nums1[i]
                    i += 1
                else:
                    value = nums2[j]
                    j += 1

            if mid_left_index == mid_right_index and index == mid_left_index:
                # 奇数个数
                mid_left_value = mid_right_value = value
                break
            else:
                # 偶数个数
                if mid_left_index == index:
                    mid_left_value = value
                if mid_right_index == index:
                    mid_right_value = value
                    break

        return (mid_left_value + mid_right_value) / 2


    def __findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 合并  O(m+n)  &  O(m+n)
        merged = []
        total_length = len(nums1) + len(nums2)
        i = j = 0
        for _ in range(total_length):
            if i == len(nums1):
                merged.append(nums2[j])
                j += 1
                continue
            if j == len(nums2):
                merged.append(nums1[i])
                i += 1
                continue

            if nums1[i] < nums2[j]:
                merged.append(nums1[i])
                i += 1
            else:
                merged.append(nums2[j])
                j += 1

        return merged[total_length//2] if total_length % 2 != 0 else (merged[total_length//2 - 1] + merged[total_length//2])/2


    def _findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 取巧
        if not nums1 and not nums2:
            return None
        result = nums1 + nums2
        result.sort()
        if len(result) == 1:
            return result[0]
        return result[len(result)//2] if len(result) % 2 != 0 else (result[len(result)//2 - 1] + result[len(result)//2])/2

if __name__ == "__main__":
    print(Solution().findMedianSortedArrays([1,3], [2]))