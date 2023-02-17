#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n+1, false));
        dp[0][0] = true;

        for (int j = 1; j < n+1; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (p[j-1] == '*') {
                    if (p[j-2] == '.' or p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i][j-2] or dp[i-1][j] or dp[i-1][j-2];
                    }else {
                        dp[i][j] = dp[i][j-2];
                    }

                }else if (p[j-1] == '.' or s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};


int main(int argc, char const *argv[]) {
    std::cout<<Solution().isMatch("aa", "a*")<<std::endl;
    return 0;
}
