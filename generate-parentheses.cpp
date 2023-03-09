#include <string>
#include <vector>

class Solution {

private:
    const static char left_parenthese = '(';
    const static char right_parenthese = ')';
    int length;

public:

    void dfs(std::string base, int left, int right, std::vector<std::string> &result){
        if (left == this->length and right == this->length) {
            result.push_back(base);
            return;
        }

        if (left < right) {
            // 剩下未使用的左括号多于右括号
            return;
        }

        if (left < this->length) {
            dfs(base + this->left_parenthese, left + 1, right, result);
        }

        if (right < this->length) {
            dfs(base + this->right_parenthese, left, right + 1, result);
        }

    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        if (n == 0) {
            return result;
        }

        this->length = n;

        dfs("", 0, 0, result);

        return result;
    }
};
