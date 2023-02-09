#include <stdio.h>
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    int i_min = 0;
    int i_max = nums1Size;
    int i = 0, j = 0, max_left = 0, min_right = 0;
    while (i_min <= i_max) {
        i = (i_min + i_max) / 2;
        j = (nums1Size + nums2Size + 1) / 2 - i;
        if (i!=0 && j != nums2Size && nums1[i-1] > nums2[j]) {
            i_max = i - 1;
        }else if (i!=nums1Size && j!=0 && nums2[j - 1] > nums1[i]) {
            i_min = i + 1;
        }else {
            if (i == 0) {
                max_left = nums2[j];
            }else if (j == 0) {
                max_left = nums1[i];
            }else {
                max_left = fmax(nums1[i-1], nums2[j-1]);
            }
            if ((nums1Size + nums2Size) % 2 != 0) {
                return max_left;
            }

            if (i == nums1Size) {
                min_right = nums2[j];
            }else if (j == nums2Size) {
                min_right = nums1[i];
            }else {
                min_right = fmin(nums1[i], nums2[j]);
            }
            return (min_right + max_left) / 2.0;
        }
    }

    return 0.0;
}

double getKTh(int* nums1_start, int* nums1_end, int* nums2_start, int* nums2_end, int k){
    if (nums1_end - nums1_start > nums2_end - nums2_start) return getKTh(nums2_start, nums2_end, nums1_start, nums1_end, k);
    if (nums1_end - nums1_start == 0) return *(nums1_start + k);
    if (1 == k) return fmin(*nums1_start, *nums2_start);
    int i_offset = nums1_end - nums1_start > k/2 ? k/2: nums1_end - nums1_start;
    int j_offset = nums2_end - nums2_start > k/2 ? k/2: nums2_end - nums2_start;
    if (*(nums1_start + i_offset - 1) > *(nums2_start + j_offset - 1)) {
        return getKTh(nums1_start, nums1_end, nums2_start + i_offset, nums2_end, k - j_offset);
    }else {
        return getKTh(nums1_start + i_offset, nums1_end, nums2_start, nums2_end, k - i_offset);
    }
};

double findMedianSortedArraysRecursive(int* nums1, int nums1Size, int* nums2, int nums2Size){
    if ((nums1Size + nums2Size) % 2 != 0) return getKTh(nums1, nums1 + nums1Size, nums2, nums2 + nums2Size, (int)(nums1Size + nums2Size)/2);
    return (
        getKTh(nums1, nums1 + nums1Size, nums2, nums2 + nums2Size, (int)(nums1Size + nums2Size)/2) +
        getKTh(nums1, nums1 + nums1Size, nums2, nums2 + nums2Size, (int)(nums1Size + nums2Size)/2 + 1)
        ) / 2.0;
}

int main(int argc, char *argv[]) {
    int nums1[] = {1, 3};
    int nums2[] = {2,4};
    printf("%f\n", findMedianSortedArrays(nums1, 2, nums2, 2));
    printf("%f\n", findMedianSortedArraysRecursive(nums1, 2, nums2, 2));
    return 0;
}
