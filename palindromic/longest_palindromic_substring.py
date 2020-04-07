"""
暴力解法：穷举所有的字串判断是否回文字符串
"""


class Solution:
    def longest_palindrome(self, s: str) -> str:
        max_sub = ""
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                sub = s[i:j]
                if self.is_palindrome(sub) and len(sub) > len(max_sub):
                    max_sub = sub
        return max_sub

    def is_palindrome(self, s: str) -> bool:
        s_c = s
        s_c = "".join(list(reversed(s_c)))
        if s == s_c:
            return True
        return False

    # ================================
    # 延伸：回文字符串两边的字符串相等, 动态扩展边界
    def extend_way(self, s: str) -> str:
        n = len(s)
        if n == 0:
            return ""
        res = s[0]

        def extend(i, j, s):
            while (i >= 0 and j < len(s) and s[i] == s[j]):
                i -= 1
                j += 1
            return s[i + 1:j]

        for i in range(n - 1):
            e1 = extend(i, i, s)
            e2 = extend(i, i + 1, s)
            if max(len(e1), len(e2)) > len(res):
                res = e1 if len(e1) > len(e2) else e2
        return res

    # ===================================
    """
    最长公共字串 => 二维矩阵横纵元素，相等则为1， 斜角为1的个数为长度 => 过程中相加即可
    动态规划
    """

    def dynamic_(self, s1):
        vec = [[0] * (len(s1)) for i in range(len(s1))]
        s2 = "".join(list(reversed(s1)))
        max_len = max_end = 0
        for i in range(len(s1)):
            for j in range(len(s2)):
                if s1[i] == s2[j]:
                    if i == 0 or j == 0:
                        vec[i][j] = 1
                    else:
                        vec[i][j] = vec[i - 1][j - 1] + 1
                if vec[i][j] > max_len:
                    max_len = vec[i][j]
                    max_end = i  # 以 i 位置结尾的字符
        return s1[max_end - max_len + 1:max_end + 1]


if __name__ == "__main__":
    print(Solution().longest_palindrome("abababab"))
    print(Solution().dynamic_("abababab"))
    print(Solution().extend_way("abababab"))
