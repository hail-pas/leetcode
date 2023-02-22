#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        std::string result = "";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].size() < i + 1 or strs[0][i] != strs[j][i]) {
                    return result;
                }
            }
            result += strs[0][i];
        }
        return result;
    }
};
