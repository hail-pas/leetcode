"""
中位数的本质：将列表分为长度相等的两个子集，右边的最小值大于右边的最大值（右边元素大于左边）
    => 求中位数，其实就是求第 `k` 小数的一种特殊情况

A => Left_A + Right_A

B => Left_B + Right_B

​	=> Left = Left_A + Left_B

​	=> Right = Right_A + Right_B

从两个列表的中间去压缩范围查找

​	初始 i_min = 0； i_max = m

​	左边 i = len(A)/2 = (i_min + i_max)/2

​	右边 i = (len(A) + len(B) + 1)/2 - i

​	比较 b[j - 1] > a[i] ==> i_min = i + 1 ==>  在右侧

​	比较 a[i - 1] > b[j] ==> i_max = i - 1 ==>  在左侧

​	相等时则确定
"""


#
def find_median_sorted_arrays(a, b):
    m = len(a)
    n = len(b)
    if m > n:
        return find_median_sorted_arrays(b, a)  # 保证 m <= n
    i_min = 0
    i_max = m
    while i_min <= i_min:
        i = (i_min + i_max) / 2  # 左列表 中位下标
        j = (m + n + 1) / 2 - i  # 右列表 中位下标
        # 改变 i 即可，j随之变化
        if j != 0 and i != m and b[j - 1] > a[i]:  # i_min 变大 在右侧
            i_min = i + 1
        elif i != 0 and j != n and a[i - 1] > b[j]:  # i_max变小 在左侧
            i_max = i - 1
        else:  # 达到要求，并且将边界条件列出来单独考虑
            if i == 0:
                max_left = b[j - 1]
            elif j == 0:
                max_left = a[i - 1]
            else:
                max_left = max(a[i - 1], b[j - 1])
            if (m + n) % 2 == 1:
                return max_left  # 奇数的话不需要考虑右半部分
            if i == m:
                min_right = b[j]
            elif j == n:
                min_right = a[i]
            else:
                min_right = min(b[j], a[i])
            return (max_left + min_right) / 2.0  # 如果是偶数的话返回结果
