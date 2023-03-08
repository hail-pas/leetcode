#include <iostream>
#include <string>
#include <map>
#include <vector>

class Solution {
public:
    bool isValid(std::string s) {
        // 40 (   41  )
        // 91 [   93  ]
        // 123 {    125 }
        int length = s.size();
        std::vector<char> stack{};
        for (auto ch: s) {
            if (!stack.empty() and (ch - *(stack.end() - 1) == 1 or ch - *(stack.end() - 1) == 2)) {
                stack.pop_back();
            }else {
                stack.push_back(ch);
            }
        }
        return stack.empty();
    }
};

int main(int argc, char const *argv[]) {
    std::string s = "()";
    std::cout<<Solution().isValid(s);
    return 0;
}
