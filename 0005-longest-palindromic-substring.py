class Solution:
    def longestPalindrome(self, s: str) -> str:
        # manacher算法 查找一个字符串的最长回文子串的线性方法
        # 本质依旧是中心扩展法，但是使用了 KMP 算法的技巧

        # 1. 字符串预处理，统一为奇长度的字符串，且首尾的字符可以做哨兵作用
        new_s = "#"
        for i in s:
            new_s += f"{i}#"

        # 2. 计算辅助数组 p； 回文半径数组 d1，记录回文串半径，此时的 p 为扩展之后的字符串半径，即为实际最长回文串的长度
        p = [0] * len(new_s)
        # 3. 字符重复访问的问题：在遍历的过程中，除了循环变量 i 以外，我们还需要记录两个变量，它们是 maxRight 和 center
        #    max_right: 当前向右扩展最远字符边界索引
        #       状态迁移：
        #           停止点：1. max_right 越界；  2. 已知 ？
        #    center：是 max_right 的回文中心的索引值； center 为 最大 max_right 对应的 i 值

        # 4. 情况讨论
        #       1. i >= max_right: 刚开始扫描或回文串右端为当前扫描索引，使用中心扩展逐步扩展 max_right
        #       2. i < max_right: 新字符的回文子串的性质，循环变量关于 center 对称的那个索引（记为 mirror_index）的 p 值就很重要;
        #                         关于 center 对称即 (mirror_index + i) / 2 = center， mirror_index = 2 * center - i
        #           2.1 p[mirror_index] < max_right - i;  此时对称的回文串是落在max_right对称点内的 p[i] = p[mirror_index]
        #           2.2 p[mirror_index] = maxRight - i; 达到边界了，有可能能继续向右扩展 max_right; 则先 p[i] = p[mirror_index] 再继续中心扩展
        #           2.3 p[mirror] > maxRight - i; 左边对称左臂超过max_right，反证法 p[i] = max_right - i, 即i为中心的回文不能再像右边扩展
        #           综上：p[i] = min(max_right - i, p[mirror_index])

        max_right, center = 0, 0
        mirror_index = 0
        start, max_length = 0, 1
        for i in range(0, len(new_s)):
            if i < max_right:
                # i < max_right 情况
                mirror_index = 2 * center - i
                p[i] = min(max_right - i, p[mirror_index])

            # 跳过 p[i] 已经确定的
            left = i - (p[i] + 1)
            right = i + (p[i] + 1)

            while left >= 0 and right < len(new_s) and new_s[left] == new_s[right]:
                p[i] += 1
                left -= 1
                right += 1

            if i + p[i] > max_right:
                max_right = i + p[i]
                center = i

            if p[i] > max_length:
                max_length = p[i]
                start = i - max_length

        s = ""
        # for index, i in enumerate(new_s):
        #     if start <= index < start + max_length:
        #         if i == "#": continue
        #         s += i
        for i in new_s[start:start + 2 * max_length]:
            if i == "#": continue
            s += i

        return s


    def _____longestPalindrome(self, s: str) -> str:
        # manacher 算法  #TODO: 未理解
        # 奇偶回文 处理：首尾及插入
        length = len(s)
        d1 = [0] * length
        l, r = 0, -1
        for i in range(0, length):
            k = 1 if i > r else min(d1[l + r - i], r - i + 1)
            while 0 <= i - k and i + k < length and s[i - k] == s[i + k]:
                k += 1
            d1[i] = k
            k -= 1
            if i + k > r:
                l = i - k
                r = i + k

        d2 = [0] * length
        l, r = 0, -1
        for i in range(0, length):
            k = 0 if i > r else min(d2[l + r - i + 1], r - i + 1)
            while 0 <= i - k - 1 and i + k < length and s[i - k - 1] == s[i + k]:
                k += 1
            d2[i] = k
            k -= 1
            if i + k > r:
                l = i - k - 1
                r = i + k

        d1_max = max(d1)
        d2_max = max(d2)

        if d1_max > d2_max:
            # length = 2 * d1_max - 1
            return s[d1.index(d1_max) - d1_max + 1:d1.index(d1_max) + d1_max]
        else:
            return s[d2.index(d2_max) - d2_max:d2.index(d2_max) + d2_max]

    def ____longestPalindrome(self, s: str) -> str:
        # 基于中心扩展d1、d2的 朴素 算法 O(n^2)  O(1)
        # 回文串的信息可用 一种更紧凑的方式 表达：对于每个位置 i = 0 ... n - 1，
        # 我们找出值 d1[i] 和 d2[i]。二者分别表示以位置 i 为中心的长度为 奇数 和 长度 为偶数的回文串个数
        # 也表示了以位置 i 为中心的最长回文串的半径长度（半径长度 d1[i]，d2[i] 均为从位置 i 到回文串最右端位置包含的字符个数
        length = len(s)
        d1, d2 = [0] * length, [0] * length

        # 朴素解法
        for i in range(0, length):
            # 奇数
            d1[i] = 1
            while i - d1[i] >= 0 and i + d1[i] < length and s[i - d1[i]] == s[i+d1[i]]:
                d1[i] += 1

            # 偶数, 往左偏移
            d2[i] = 0
            while i - d2[i] - 1 >= 0 and i + d2[i] < length and s[i - d2[i] - 1] == s[i+d2[i]]:
                d2[i] += 1
        d1_max = max(d1)
        d2_max = max(d2)

        if d1_max > d2_max:
            # length = 2 * d1_max - 1
            return s[d1.index(d1_max) - d1_max + 1:d1.index(d1_max) + d1_max]
        else:
            return s[d2.index(d2_max) - d2_max:d2.index(d2_max) + d2_max]

    def ___longestPalindrome(self, s: str) -> str:
        # 中心扩展算法，注意中断扩展
        # 状态转移：P(i,j)←P(i+1,j−1)←P(i+2,j−2) ←⋯← 某一边界情况(中心)
        # 所有的状态在转移的时候的可能性都是唯一的，则从任意边界反推就能获取所有的状态
        if not s:
            return s
        start = end = 0
        for i in range(len(s)):
            left, right = self.expand_around_center(s, i)
            if right - left > end - start:
                start, end = left, right

        return s[start: end + 1]

    def expand_around_center(self, s, index):
        # 当为偶数时向右扩展，则只有右边界
        if index >= len(s) - 1:
            return index, index
        # 奇数扩展
        left1 = index
        right1 = index
        for i in range(index - 1, -1, -1):
            t_left1 = i
            t_right1 = index - i + index
            if t_left1 >= 0 and t_right1 <= len(s) - 1 and s[t_left1] == s[t_right1]:
                left1 = t_left1
                right1 = t_right1
            else:
                # 无须继续
                break

        # 偶数扩展
        if s[index] == s[index + 1]:
            left2 = index
            right2 = index + 1
            for i in range(index - 1, -1, -1):
                t_left2 = i
                t_right2 = index - i + index + 1
                if t_left2 >= 0 and t_right2 <= len(s) - 1 and s[t_left2] == s[t_right2]:
                    left2 = t_left2
                    right2 = t_right2
                else:
                    break

            return (left1, right1) if right1 - left1 > right2 - left2 else (left2, right2)

        return left1, right1

    def __longestPalindrome(self, s: str) -> str:
        # 动态规划：O(n^2)  O(n^2)
        # P(i, j) = P(i+1, j-1) and (Si==Sj), 其子串是回文及当前两端字符相等
        n = len(s)
        if n < 2:
            return s

        max_length = 1
        begin = 0
        # 创建状态矩阵，记录 s[i:j] 是否是回文
        dp = [[False] * n for _ in range(n)]

        # 单字符置为是回文
        for i in range(n):
            dp[i][i] = True

        for length in range(2, n+1):
            for i in range(n):
                j = length + i - 1 # 右边界
                if j >= n: # 越界
                    break
                if s[i] != s[j]:
                    dp[i][j] = False
                else:
                    if length <= 3: # 防止 i+1 j-1 越界 即 子串长度小于4则直接为回文串
                        dp[i][j] = True
                    else:
                        dp[i][j] = dp[i+1][j-1] # 当前边缘两端的字符相等，且内一层的两端字符也相等
                if dp[i][j] and j - i + 1 >max_length:
                    max_length = j - i + 1
                    begin = i

        return s[begin:begin + max_length]

    def _longestPalindrome(self, s: str) -> str:
        # 暴力解法：O(n^3) O(1)
        if len(s) < 2:
            return s

        for i in range(len(s), 1, -1):
            for j in range(len(s) - i + 1):
                if self.is_palindrome(s[j:j+i]):
                    return s[j:j+i]
        return s[0]

    def is_palindrome(self, s):
        for i in range((len(s)+1)//2):
            if s[i] != s[-(i+1)]:
                return False

        return True

if __name__ == "__main__":
    print(Solution().longestPalindrome("babad"))
