#include <algorithm>
#include <vector>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int length = nums.size();
        std::sort(nums.begin(), nums.end());
        int three_sum = nums[0] + nums[1] + nums[2];
        int gap = target - three_sum;
        gap = gap > 0 ? gap: -gap;
        int i, j, k;
        int temp_sum, temp_gap;
        for (i = 0; i < length - 2; i++) {
            if (i > 0 and nums[i] == nums[i-1]) continue;
            j = i + 1;
            k = length - 1;
            while (j < k) {
                temp_sum = nums[i] + nums[j] + nums[k];
                temp_gap = target - temp_sum;
                if (temp_gap == 0) return temp_sum;
                if (temp_gap > 0) {  // 在 target 左边，需要增大，即 j 右移
                    j++;
                }
                else {   // 在 target 左边，需要增大，即 j 右移
                    temp_gap = -temp_gap;
                    k--;
                }
                if (temp_gap < gap) {
                    gap = temp_gap;
                    three_sum = temp_sum;
                }
            }
        }
        return three_sum;
    }
};
