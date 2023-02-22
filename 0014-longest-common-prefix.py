from typing import List

class Solution:
    def ___longestCommonPrefix(self, strs: List[str]) -> str:
        # 分治
        return "" if not strs else self.bin_lcp(strs, 0, len(strs) - 1)

    def bin_lcp(self, strs, start, end):
        if start == end:
            return strs[start]

        mid = (start + end) // 2

        lcp_left = self.bin_lcp(strs, start, mid)
        lcp_right = self.bin_lcp(strs, mid + 1, end)

        min_length = min(len(lcp_left), len(lcp_right))

        for i in range(min_length):
            if lcp_left[i] != lcp_right[i]:
                return lcp_left[:i]

        return lcp_left[:min_length]

    def __longestCommonPrefix(self, strs: List[str]) -> str:
        # 横向扫描
        if not strs:
            return ""
        result = strs[0]

        for i in range(1, len(strs)):
            result = self.lcp(result, strs[i])
            if not result:
                break

        return result

    def lcp(self, str1, str2):
        min_length, index = min(len(str1), len(str2)), 0
        while index < min_length and str1[index] == str2[index]:
            index += 1
        return str1[:index]

    def _longestCommonPrefix(self, strs: List[str]) -> str:
        # 纵向扫描
        if not strs:
            return ""
        result = ""

        for index, ch in enumerate(strs[0]):
            for j in strs[1:]:
                if len(j) < index + 1 or j[index] != ch:
                    return result
            result += ch

        return result
