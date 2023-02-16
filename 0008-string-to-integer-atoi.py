INT_MIN, INT_MAX = -2**31, 2**31-1

class AutomationEndException(Exception):
    pass


class Automation:
    def __init__(self) -> None:
        self.state = "start"
        self.sign = 1
        self.ans = 0
        self.trans_table = {
            # 点 --线--> 点
            # 状态：start、signed、in_number、end
            # 输入情况：' '、 +/-、number、other
            # 触发迁移表： 状态 * 情况
            #           ' '、     +/-、     number、    other
            "start": ["start", "signed", "in_number", "end"],
            "signed": ["end", "end", "in_number", "end"],
            "in_number": ["end", "end", "in_number", "end"],
            "end": ["end", "end", "end", "end"]
        }

    def get_state_column(self, c):
        if c.isspace():
            return 0
        if c in "+-":
            return 1
        if c.isdigit():
            return 2
        return 3

    def transfer(self, c):
        self.state = self.trans_table[self.state][self.get_state_column(c)]
        if self.state == "in_number":
            self.ans = self.ans * 10 + int(c)
            self.ans = min(self.ans, INT_MAX) if self.sign == 1 else min(self.ans, -INT_MIN)
        elif self.state == "signed":
            self.sign = 1 if c == "+" else -1
        elif self.state == "end":
            raise AutomationEndException()


class Solution:
    def myAtoi(self, s: str) -> int:
        # 状态机
        automation = Automation()
        for c in s:
            try:
                automation.transfer(c)
            except AutomationEndException:
                break

        return automation.sign * automation.ans

    def _myAtoi(self, s: str) -> int:
        # 遍历处理
        digits = 10
        result = 0
        flag = 1
        initilized = False
        for i in s:
            if not initilized:
                if i in "-+":
                    flag = (44 - ord(i)) * flag
                    initilized = True
                    continue
                elif i == ' ':
                    continue
                elif i > '9' or i < '0':
                    break
            if '0' <= i <= '9':
                initilized = True
                result = result * digits + (ord(i) - 48)
                if result * flag > INT_MAX:
                    return INT_MAX
                if result * flag < INT_MIN:
                    return INT_MIN
            elif initilized:
                break

        result = flag * result

        return result

if __name__ == "__main__":
    print(Solution().myAtoi("42"))
