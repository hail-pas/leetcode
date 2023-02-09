#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        if (nums1.size() == 0 and nums2.size() == 0) return 0.0;
        if (nums1.size() < nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int i_min = 0;
        int i_max = m;
        int i = 0, j = 0, max_left = 0, min_right = 0;
        while (i_min <= i_max) {
            i = (i_min + i_max) / 2;
            j = (m + n + 1) / 2 - i;
            if (i != 0 && j != n && nums1[i - 1] > nums2[j]) {
                i_max = i - 1;
            }else if (j!=0 && i!= m && nums2[j - 1]> nums1[i]) {
                i_min = i + 1;
            }else {
                if (i == 0) {
                    max_left = nums2[j];
                }else if (j == 0) {
                    max_left = nums1[i];
                }else {
                    max_left = std::max(nums1[i-1], nums2[j-1]);
                }
                if ((m + n) % 2 != 0) {
                    return max_left;
                }

                if (i==m) {
                    min_right = nums2[j];
                }else if (j == n) {
                    min_right = nums1[i];
                }else {
                    min_right = std::min(nums1[i], nums2[j]);
                }
                return (max_left + min_right) / 2.0;
            }
        }
        return 0.0;
    }
};

int main(int argc, char const *argv[]) {
    std::cout<<Solution().findMedianSortedArrays({1, 3}, {2, 4})<<std::endl;
    return 0;
}