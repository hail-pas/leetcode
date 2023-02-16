class Solution:

    def isPalindrome(self, x: int) -> bool:
        # 取巧：return str(x) == str(x)[::-1]
        # 反转数字的一半，如果相等则是回文，无须计算长度
        result = True
        if x < 0 or (x % 10 == 0 and x != 0) :
            return False

        if x < 10:
            return True

        half_reversed = 0

        while x > half_reversed:
            half_reversed = half_reversed * 10 + x % 10
            x = x // 10

        length, temp = 0, 0

        # while temp:
        #     length += 1
        #     temp = temp // 10

        # for i in range(length//2):
        #     left = (x // 10**(length - i - 1)) % 10
        #     right = (x // 10**i) % 10
        #     if left != right:
        #         return False

        # return result
        # 需要考虑奇回文 与 偶回文
        return half_reversed == x or half_reversed // 10 == x

if __name__ == "__main__":
    print(Solution().isPalindrome(121))
