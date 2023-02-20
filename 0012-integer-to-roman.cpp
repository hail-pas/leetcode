#include <iostream>
#include <string>
#include <map>

class Solution {
public:
    std::string intToRoman(int num) {
        std::map<int, std::string, std::greater<int>> roman_identifier = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"},
        };

        std::string result = "";

        for (auto pair: roman_identifier) {
            if (num < pair.first) continue;
            int key_nums = num / pair.first;
            while (key_nums > 0) {
                result += pair.second;
                key_nums--;
            }
            num = num % pair.first;
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    int num = 58;
    std::cout<<Solution().intToRoman(num)<<std::endl;
    return 0;
}
