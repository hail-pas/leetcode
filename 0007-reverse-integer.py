class Solution:
    def reverse(self, x: int) -> int:
        flag = 1
        if x < 0:
            flag = -flag
            x = -x
        result = 0
        while x != 0:
            current_value = x % 10
            x = x // 10
            result = result * 10 + current_value

        result *= flag

        if -2**31 <= result <= 2**31 - 1:
            return result

        return 0


if __name__ == "__main__":
    print(Solution().reverse(-123))
