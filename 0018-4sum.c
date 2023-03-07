#include <stdlib.h>

int comp(const void * pa, const void * pb) {
    int a = *(int *)pa;
    int b = *(int *)pb;
    return a > b ? 1 : -1;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize < 4) {
        return NULL;
    }

    long l_sum = 0;

    // 排序
    qsort(nums, numsSize, sizeof(int), comp);
    int base = 100;
    int ** result = (int**)malloc(base*sizeof(int *));
    *returnColumnSizes = (int *)malloc(base*sizeof(int));
    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i - 1] == nums[i]) {
            // 去重
            continue;
        }
        l_sum = (long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
        if (l_sum > target) {
            // 最小的四个数都大于 target
            break;;
        }
        l_sum = (long)nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3];
        if (l_sum < target) {
            // 当前i的最大值小于 target 继续增大 i
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i+ 1 && nums[j] == nums[j - 1]) {
                // 去重
                continue;
            }
            l_sum = (long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
            if (l_sum > target) {
                break;
            }
            l_sum = (long)nums[i] + nums[j] + nums[numsSize - 1] + nums[numsSize - 2];
            if (l_sum < target) {
                continue;
            }

            int k = j + 1;
            int l = numsSize - 1;

            while (k < l) {
                l_sum = (long)nums[i] + nums[j] + nums[k] + nums[l];
                if (l_sum == target) {
                    if ((*returnSize) >= base - 1) {
                        base += 100;
                        result = (int **)realloc(result, sizeof(int *) * base);
                        *returnColumnSizes = (int *)realloc(*returnColumnSizes, base*sizeof(int));
                    }
                    int * temp = (int *)malloc(4 * sizeof(int));
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    temp[3] = nums[l];
                    (*returnColumnSizes)[*returnSize] = 4;
                    result[(*returnSize)++] = temp;
                    while (k < l && nums[k] == nums[k+1]) {
                        k++;
                    }
                    k++;
                    while (k < l && nums[l] == nums[l-1]) {
                        l--;
                    }
                    l--;
                } else if (l_sum > target) {
                    l--;
                } else {
                    k++;
                }
            }
        }
    }
    return result;
}