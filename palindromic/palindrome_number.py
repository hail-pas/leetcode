"""
暴力：
    数字专为字符串 -> { 倒置判断 }
"""


def is_palindromic_force(number: int):
    if number < 0:
        return False
    r_number = "".join(reversed(str(number)))
    if number == r_number:
        return True
    return False


"""
数学解法：
    利用整除//和取余% 取出两头的数字做比较
"""


def is_palindromic_math(number: int):
    if number < 0:
        return False
    div = 1
    while number / div >= 10:
        div *= 10  # 获取数字最大位数
    while number > 0:
        left = number / div
        right = number % 10
        if left != right:
            return False
        number = number % div / 10  # 去两头数字
        div /= 100  # div相应的减两位
    return True


"""
折半取：
    取后半段的数字倒序排成新数字，比较是否相等
    临界条件 - 原数字 小于 新数字时 则停止继续取
    比较 - 区分 奇偶
"""


def is_palindromic_half(number: int):
    if number < 0 or (number % 10 == 0 and number != 0):
        return False
    reversed_num = 0
    while number > reversed_num:
        reversed_num = reversed_num * 10 + number % 10  # 加一位
        number /= 10  # 减一位
    return number == reversed_num or number == reversed_num / 10
