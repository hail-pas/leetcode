#include <stdio.h>
#include <stdlib.h>

int cmp(const void *pa, const void *pb) {
    int a = *(int *)pa;
    int b = *(int *)pb;
    return a > b ? 1 : -1;
}


int threeSumClosest(int* nums, int numsSize, int target){
    if (numsSize < 3) return 0;
    int three_sum = nums[0] + nums[1] + nums[2];
    int gap = target - three_sum;
    gap = gap > 0 ? gap : -gap;
    int i, j, k;
    int temp_sum, temp_gap;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (i=0; i<numsSize - 2; i++) {
        if (i>0 && nums[i] == nums[i-1]) {
            continue;
        }
        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            temp_sum = nums[i] + nums[j] + nums[k];
            temp_gap = target - temp_sum;
            if (temp_gap == 0) {
                return temp_sum;
            }
            if (temp_gap > 0) { // 在 target 左边，j 增大
                j++;
            }else {
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


int main(int argc, char *argv[]) {
    int nums[] = {4,0,5,-5,3,3,0,-4,-5};
    printf("%d\n", threeSumClosest(nums, 9, -2));
    return 0;
}
