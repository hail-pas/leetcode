"""
利用新的列表来存储子串并作为后续字母的比对源，每次遇到又重复的字母时则将其情空，
将此时的子串列表的长度保存到长度列表，
每一个字符k开头的子串都要做一次，最后将最大的长度返回
"""


def length_of_longest_substring(s):
    """
    :type s: str
    :rtype: int
    """
    sub_s = []
    count_l = []
    index = 0
    while index < len(s):
        for i in range(index, len(s)):
            if s[i] not in sub_s:
                sub_s.append(s[i])
            else:
                count_l.append(len(sub_s))
                sub_s.clear()
                break
        index += 1
    return max(count_l)


"""
滑动窗口优化
变量：子串集合、子串长度、最大长度、子串第一个元素下标
"""


def length_of_longest_substring_win(s: str) -> int:
    if not s:
        return 0
    left = 0
    lookup = set()
    max_len = 0
    cur_len = 0
    for i in range(len(s)):
        cur_len += 1  # 当前长度
        while s[i] in lookup:
            # 是一个滑动窗口，确保里面无重复元素； 可以适当的延展成其他条件
            lookup.remove(s[left])  # 从左边开始移除元素直至无重复元素，获得一个子串
            left += 1
            cur_len -= 1  # 相应的该子串长度减1
        if cur_len > max_len: max_len = cur_len  # 只记录最大子串
        lookup.add(s[i])
    return max_len
