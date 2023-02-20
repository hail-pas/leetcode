#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int result = 0;
        int temp_s = 0, temp_h = 0;
        int left_index = 0;
        int right_index = height.size() - 1;
        while (left_index < right_index) {
            temp_h = std::min(height[left_index], height[right_index]);
            temp_s = (right_index - left_index) * temp_h;
            if (temp_s > result) {
                result = temp_s;
            }
            while (height[left_index] <= temp_h and left_index < right_index) {
                left_index ++;
            }
            while (height[right_index] <= temp_h and left_index < right_index) {
                right_index--;
            }

        }
        return result;
    }
};
