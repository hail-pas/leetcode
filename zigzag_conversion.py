class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        l = len(s)
        cycle_len = 2 * numRows - 2
        rows = []
        for i in range(l):
            if i < numRows:
                rows.append(s[i])
            else:
                if i % cycle_len in range(numRows):
                    rows[i % cycle_len] += s[i]
                elif i % cycle_len in range(numRows, cycle_len):
                    rows[cycle_len - i % cycle_len] += s[i]
        final_s = "".join(rows)
        return final_s


if __name__ == "__main__":
    print(Solution().convert(s="PAYPALISHIRING", numRows=4))
