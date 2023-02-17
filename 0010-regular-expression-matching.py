class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # 递归，有可能执行时间太久
        if len(p) == 0:
            return len(s) == 0
        headMatch = len(s) >= 1 and (s[0] == p[0] or p[0] == '.')
        if len(p) >= 2 and p[1] == '*': # 让'*'匹配0个字符并被删除，或者让'*'匹配1个字符并被保留。递归场景里面则包含了匹配0、1、多的情况
            return self.isMatch(s, p[2:]) or (headMatch and self.isMatch(s[1:], p))
        return headMatch and self.isMatch(s[1:], p[1:])

    def isMatch(self, s: str, p: str) -> bool:
        # 动态规划：状态转移 + 边界情况
        # A. 动态迁移
        # m[i][j] 表示 长度为 i 的s串 和 长度为 j 的 p 串是否匹配
        # 1. s[i-1] == p[j-1] or p[j-1] == '.' ==> m[i][j] = m[i-1][j-1]
        # 2. p[j-1] == '*':
        #       2.1 s[i-1] == p[j-2] or p[j-2] == '.', 任意一种皆可
        #            2.1.1 p[j-2]和p[j-1] 一起消失，匹配0次; 和 other 相同：m[i][j] = m[i][j-2]
        #            2.1.2 匹配一次, m[i][j] = m[i-1][j-2]
        #            2.1.3 匹配多次, 抵消s[i-1]考察s[i-2]及之前的s； m[i][j] = m[i-1][j]
        #       2.2 other : 考察 s[i-1] 及之前的s 和 p[j-3]之前的p 是否匹配 即 m[i][j] = m[i][j-2]
        # B. 边界情况
        # 1. p为空，s为空，匹配 m[0][0] = True
        # 2. p为空，s不为空，不匹配 m[i][0] = False | i >= 1
        # 3. s为空，p不为空， 只有右端是*不断消除
        #       3.1 j - 1 是 * ==> m[0][j] = m[0][j-2]
        #       3.2 j - 1 非 * ==> m[0][j] = False

        # * 和 非* 两种情况
        l1, l2 = len(s), len(p)

        # 动态迁移表
        m = [[False] * (l2 + 1) for _ in range(l1 + 1)]

        m[0][0] = True # 都是空串

        for j in range(1, l2+1):
            # j - 1 为 * 则一定存在 j - 2
            if p[j-1] == '*': m[0][j] = m[0][j-2]

        for i in range(1, l1 + 1):
            for j in range(1, l2 + 1):
                if p[j-1] == '*':
                    if s[i-1] == p[j-2] or p[j-2] == '.':
                        m[i][j] = m[i][j-2] or m[i-1][j-2] or m[i-1][j]
                    else:
                        m[i][j] = m[i][j-2]
                elif p[j-1] == '.' or s[i-1] == p[j-1]:
                    m[i][j] = m[i-1][j-1]

        return m[l1][l2]


if __name__ == "__main__":
    print(Solution().isMatch("aa", "a*"))
