"""
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is
found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical
digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no
effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists
because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range:
[−2**31,  2**31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2**31 − 1) or
INT_MIN (−2**31) is returned.
"""


class Solution:
    def myAtoi(self, str: str) -> int:
        MAX_VALUE = 2147483647
        MIN_VALUE = -2147483648
        sign = 1  # 正负标识位
        ans = 0
        has_sign = False  # 代表是否开始转换数字
        for i in str:
            if i == ' ' and not has_sign:
                continue
            if i == '-' and not has_sign:
                sign = -1
                has_sign = True
                continue
            if i == '+' and not has_sign:
                sign = 1
                has_sign = True
                continue
            if '9' >= i >= '0':
                has_sign = True
                pop = int(i)
                ans = ans * 10 + pop
                if ans * sign < MIN_VALUE:
                    return MIN_VALUE
                if ans * sign > MAX_VALUE:
                    return MAX_VALUE
            else:
                return ans * sign
        return ans * sign
