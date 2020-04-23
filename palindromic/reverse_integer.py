class Solution:
    def reverse(self, x: int) -> int:
        rev = 0
        copy_x = x
        if x < 0:
            copy_x = -x
        while copy_x != 0:  # 边界条件
            pop = copy_x % 10  # 取位
            copy_x //= 10  # 减位
            if rev > (2 ** 31 - 1) // 10:  # 溢出判断， python不区分类型， int不够自动转换到长类型可以无穷大
                return 0
            if rev < (-2 ** 31) // 10:
                return 0
            rev = rev * 10 + pop
        return rev if x > 0 else -rev
