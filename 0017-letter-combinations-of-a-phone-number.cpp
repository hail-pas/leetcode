#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <deque>
#include <map>

class Solution {
private:
    std::map<char, std::string> convert_map = {
        std::pair<char, std::string>{'2', "abc"},
        std::pair<char, std::string>{'3', "def"},
        std::pair<char, std::string>{'4', "ghi"},
        std::pair<char, std::string>{'5', "jkl"},
        std::pair<char, std::string>{'6', "mno"},
        std::pair<char, std::string>{'7', "pqrs"},
        std::pair<char, std::string>{'8', "tuv"},
        std::pair<char, std::string>{'9', "wxyz"},
    };
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        int length = digits.size();
        if (length == 0) {
            return {};
        }
        // int total = 1;
        // for (int i = 0; i < length; i++) {
        //     auto pair = this->convert_map.find(digits.at(i));
        //     total *= pair->second.size();
        // }
        std::deque<std::string> result{""};
        // backtrack(result, "", digits);
        for (auto ch: digits) {
            int r_size = result.size();
            for (int i = 0; i < r_size; i++) {
                auto cur = result.back();
                result.pop_back();
                auto pair = this->convert_map.find(ch);
                for (auto letter: pair->second) {
                    result.push_front(cur + letter);
                }
            }
        }
        return std::vector<std::string>{result.begin(), result.end()};
    }

    void backtrack(std::vector<std::string> & result, std::string conbination, std::string digits){
        if (digits.size() == 0) {
            result.push_back(conbination);
        }else {
            auto pair = this->convert_map.find(digits.at(0));
            for (auto ch: pair->second) {
                backtrack(result, conbination + ch, digits.substr(1, digits.size() - 1));
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    std::string digits = "23";
    for (auto s: Solution().letterCombinations(digits)) {
        std::cout<<s<<std::endl;
    }
    return 0;
}