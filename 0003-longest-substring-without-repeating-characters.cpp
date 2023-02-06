#include <algorithm>
#include <string>
#include <math.h>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // std::string window = "";
        int window_start = 0;
        int max_length = 0;
        for (int i = 0; i < s.length(); i++) {
            auto find_index = s.substr(window_start, i - window_start).find(s[i]);
            if (find_index != std::string::npos) {
                window_start += find_index + 1;
            }
            max_length = std::max(i - window_start + 1, max_length);
        }
        return max_length;
    }
};

int main(int argc, char *argv[]){
    std::string s = "pwwkew";
    std::cout<<Solution().lengthOfLongestSubstring(s)<<std::endl;
    return 0;
}