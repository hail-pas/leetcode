class Solution:

    def isValid(self, s: str) -> bool:
        # 字符串替换（没有其他字符的前提下）
        if len(s) % 2 != 0:
            return False
        while '{}' in s or '()' in s or '[]' in s:
            s = s.replace("[]", "")
            s = s.replace("()", "")
            s = s.replace("{}", "")

        return s == ""

    offset_map = {
        "(": ")",
        "{": "}",
        "[": "]"
    }

    def _isValid(self, s: str) -> bool:
        # 栈
        if len(s) % 2 != 0:
            return False
        stack = []
        for ch in s:
            if stack and self.offset_map.get(stack[-1]) == ch:
                stack.pop()
            else:
                stack.append(ch)
        if not stack:
            return True

        return False


if __name__ == "__main__":
    s = "()"
    print(Solution().isValid(s))
