#include <stdlib.h>

int comp (const void * a, const void * b) {
    return * (int *) a >= * (int *) b;
}

int maximumProduct(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);

    int sum1 = nums[0] * nums[1] * nums[numsSize - 1];
    int sum2 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];

    int ret_sum = sum1 > sum2 ? sum1 : sum2;
    return ret_sum;
}
