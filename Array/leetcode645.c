/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int comp (const void * a, const void * b) {
    return * (int *) a >= * (int *) b;
}

int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int tmp = (1 + numsSize) * numsSize / 2;
    int * retT = (int *) malloc (sizeof(int) * 2);
    * returnSize = 2;
    qsort(nums, numsSize, sizeof(int), comp);
    tmp -= nums[0];
    for (int i = 1; i < numsSize; i ++) {
        if (nums[i] == nums[i - 1]) {
            retT[0] = nums[i];
        }
        tmp -= nums[i];
    }
    retT[1] = retT[0] + tmp;
    return retT;
}
