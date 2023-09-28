/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>

int comp(const void * a, const void * b) {
    return * (int *) a >= * (int *) b;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    int n = 1;
    int * retT = (int *)malloc(sizeof(int) * numsSize);
    memset(retT, 0, sizeof(int) * numsSize);
    int index = 0;
    * returnSize = 0;

    qsort(nums, numsSize, sizeof(int), comp);

    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] <= n) {
            if (nums[i] == n) {
                n ++;
            }
        } else {
            while(n < nums[i]) {
                * returnSize = * returnSize + 1;
                retT[index ++] = n ++;
            }
            n ++;
        }

        if (i == numsSize - 1) {
            n = nums[i] + 1;
            while (n <= numsSize) {
                * returnSize = * returnSize + 1;
                retT[index ++] = n ++;
            }
        }
    }

    return retT;
}
