class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # 遍历然后按行存储
        # 关键点在于 反转 存储索引： flag = - flag

        if numRows <= 1:
            return s

        res = [""] * numRows

        i, flag = 0, -1

        for c in s:
            res[i] += c
            if i == 0 or i == numRows - 1: flag = - flag
            i += flag

        return "".join(res)

if __name__ == "__main__":
    print(Solution().convert("PAYPALISHIRING", 3))
