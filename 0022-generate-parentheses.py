import queue


class Solution(object):
    left_parenthese = "("
    right_parenthese = ")"

    def generateParenthesis(self, n):
        # 基于广度优先 - 队列，先入先出
        result = []

        if n == 0: return result

        # if n == 1: return ["()"]

        # 基于广度遍历
        class Node:
            cur_str: str
            remain_left_count: int
            remain_right_count: int


            def __init__(self, cur_str, remain_left_count, remain_right_count) -> None:
                self.cur_str = cur_str
                self.remain_left_count = remain_left_count
                self.remain_right_count = remain_right_count

        q = queue.Queue()

        q.put(Node("", n, n))

        while not q.empty():
            cur_node: Node = q.get()
            if cur_node.remain_left_count == 0 and cur_node.remain_right_count == 0:
                result.append(cur_node.cur_str)

            # 先用 左括号
            if cur_node.remain_left_count > 0 and cur_node.remain_left_count <= cur_node.remain_right_count:
                q.put(Node(cur_node.cur_str + self.left_parenthese, cur_node.remain_left_count - 1, cur_node.remain_right_count))

            if cur_node.remain_right_count > 0 and cur_node.remain_left_count <= cur_node.remain_right_count:
                q.put(Node(cur_node.cur_str + self.right_parenthese, cur_node.remain_left_count, cur_node.remain_right_count - 1))

        return result


    def _generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # 基于树的深度遍历 - 栈; 系统栈
        # 根结点 left_count:n + right_count:n --使用左括号--> left_count:n-1 + right_count:n --使用右节点--> left_count:n-1 + right_count:n-1
        # 剪枝：left_count > right_count
        # 结果：left_count = right_count = 0

        def dfs(base, left_length, right_length, result):
            if left_length == n and right_length == n:
                result.append(base)

            if left_length < right_length:  # 减枝
                return

            if left_length < n: # 使用左括号，中序深度遍历；必然左括号开始
                # 使用 减法 会导致 left_length < right_length 生成的事反括号 ==> 结束条件去反
                dfs(base + self.left_parenthese, left_length + 1, right_length, result)

            if right_length < n:
                dfs(base + self.right_parenthese, left_length, right_length + 1, result)

        result = []

        if n == 0: return result

        # if n == 1: return ["()"]

        dfs("", 0, 0, result)

        return result

if __name__ == "__main__":
    n = 3
    print(Solution().generateParenthesis(n))
    print(Solution()._generateParenthesis(n))
