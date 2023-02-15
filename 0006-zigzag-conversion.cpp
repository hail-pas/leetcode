#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows < 2) {
            return s;
        }
        std::vector<std::string> res(numRows);
        int i = 0, flag = -1;
        for (auto c: s){
            res[i] += c;
            if (i==0 or i==numRows - 1) {
                flag = -flag;
            }
            i += flag;
        }
        std::string result;
        for (auto ts: res) {
            result += ts;
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    std::string s = "AB";
    std::cout<<Solution().convert(s, 3)<<std::endl;
    return 0;
}