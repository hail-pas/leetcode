#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result{};
        std::sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i <= length - 3; i++) {
            if (nums[i] > 0) break;
            if (i >= 1 and nums[i] == nums[i-1]) continue;
            int k = length - 1;
            for (int j = i + 1; j <= length - 2; j++) {
                if (j > i + 1 and nums[j] == nums[j - 1]) continue;
                while (j < k and nums[j] + nums[k] > -nums[i]) {
                    k--;
                }
                if (j == k) {
                    break;
                }
                if (nums[j] + nums[k] == -nums[i]) {
                    result.push_back(std::vector<int>({nums[i], nums[j],nums[k]}));
                }
            }
        }
        return result;
    }
};