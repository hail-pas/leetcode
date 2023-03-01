#include <stdlib.h>
#include <stdio.h>

int cmp(const void *pa, const void *pb) {
    int a = *(int *)pa;
    int b = *(int *)pb;
    return a > b ? 1 : -1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **threeSum(int *nums, int numsSize, int *returnSize,
               int **returnColumnSizes) {
    int base = 100;
    int **res = (int **)malloc(sizeof(int *) * base);
    *returnColumnSizes = (int *)malloc(sizeof(int) * base);
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int k = numsSize - 1;
        int target = -nums[i];
        for (int j = i + 1; j < numsSize - 1; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            while (j < k && nums[j] + nums[k] > target)
                k -= 1;
            if (j == k)
                break;
            if (nums[j] + nums[k] == target) {
                if (*returnSize == base) {
                    base *= 2;
                    res = (int **)realloc(res, sizeof(int *) * base);
                    *returnColumnSizes =
                        (int *)realloc(*returnColumnSizes, sizeof(int) * base);
                }
                res[*returnSize] = (int *)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[j];
                res[*returnSize][2] = nums[k];
                (*returnSize)++;
            }
        }
    }
    return res;
}


int main(int argc, char *argv[]) {
    int test_data[] = {34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49};
    int *returnSize = (int *)malloc(sizeof(int));
    int **returnColumnSizes = (int **)malloc(sizeof(int *) * 55);;
    int **res = threeSum(test_data, 55, returnSize, returnColumnSizes);
    for (int i = 0; i < *returnSize; i++) {
        for (int j = 0; j<3; j++) {
            printf("%d ", *(*(res+i)+j));
        }
    }
    return 0;
}
