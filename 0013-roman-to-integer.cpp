#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <vector>

class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;
        std::vector<int> values = {1000, 500, 100, 50, 10, 5, 1};
        std::vector<char> reprs = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

        for (int i = 0; i < s.size(); i++) {
            auto current_roman_index = std::find(reprs.begin(), reprs.end(), s[i]) - reprs.begin();
            if (i + 1 < s.size()) {
                auto next_roman_index = std::find(reprs.begin(), reprs.end(), s[i + 1]) - reprs.begin();
                if (values[current_roman_index] < values[next_roman_index]) {
                    result -= values[current_roman_index];
                }else {
                    result += values[current_roman_index];
                }
            }else {
                result += values[current_roman_index];
            }
        }
        return result;
    }
};