#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    std::string longestPalindrome(std::string s) {

        return "";
    }
    std::string __longestPalindrome(std::string s) {
        // 中心扩展,
        std::vector<int> d1(s.length()), d2(s.length());
        for (int i = 0; i < s.length(); i++) {
            d1[i] = 1;
            while (0 <= i - d1[i] && i + d1[i] < s.length() && s[i - d1[i]] == s[i + d1[i]]) {
                d1[i]++;
            }

            d2[i] = 0;
            while (0 <= i - d2[i] - 1 && i + d2[i] < s.length() &&
                    s[i - d2[i] - 1] == s[i + d2[i]]) {
                d2[i]++;
            }
        }
        auto d1_max_iter = std::max_element(d1.begin(), d1.end());
        auto d2_max_iter = std::max_element(d2.begin(), d2.end());
        if (*d1_max_iter > *d2_max_iter) {
            return s.substr(d1_max_iter - d1.begin() - *d1_max_iter + 1, *d1_max_iter * 2 - 1);
        }else {
            return s.substr(d2_max_iter - d2.begin() - *d2_max_iter, *d2_max_iter * 2);
        }
    }
};

int main(int argc, char const *argv[]) {
    std::string s = "bb";
    std::cout<<Solution().longestPalindrome(s);
    return 0;
}