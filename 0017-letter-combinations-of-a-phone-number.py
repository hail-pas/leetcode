from typing import List

class Solution:
    convert_map = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    def letterCombinations(self, digits: str) -> List[str]:
        # 回溯
        result = []
        if not digits:
            return result

        def backtrack(conbination, nextdigit):
            if len(nextdigit) == 0:
                result.append(conbination)
            else:
                for letter in self.convert_map[nextdigit[0]]:
                    backtrack(conbination + letter,nextdigit[1:])

        backtrack('',digits)
        return result


    def __letterCombinations(self, digits: str) -> List[str]:
        # 队列
        if not digits:
            return []

        result = [""]

        for digit in digits:
            for _ in range(len(result)):
                tmp = result.pop(0)
                for letter in self.convert_map[digit]:
                    result.append(tmp + letter)

        return result

    def _letterCombinations(self, digits: str) -> List[str]:
        # 暴力四层循环，使用空字符做哨兵

        result = []
        if not digits:
            return result

        wait_to_use = [" "] * 4
        vertical_length = [0] * 4
        i = 0

        for d in digits:
            if d in "23456789":
                wait_to_use[i] = self.convert_map[d]
                vertical_length[i] = len(self.convert_map[d])
                i += 1

        for i in range(vertical_length[0]):
            for j in range(max(vertical_length[1], 1)):
                temp = wait_to_use[0][i]
                if wait_to_use[1][j] == " ":
                    result.append(temp)
                    break
                for k in range(max(vertical_length[2], 1)):
                    temp = wait_to_use[0][i] + wait_to_use[1][j]
                    if wait_to_use[2][k] == " ":
                        result.append(temp)
                        break
                    for l in range(max(vertical_length[3], 1)):
                        temp = wait_to_use[0][i] + wait_to_use[1][j] + wait_to_use[2][k]
                        if wait_to_use[3][l] == " ":
                            result.append(temp)
                            break
                        temp +=  wait_to_use[3][l]
                        result.append(temp)

        return result


if __name__ == "__main__":
    digits = "23"
    print(Solution().letterCombinations(digits))
