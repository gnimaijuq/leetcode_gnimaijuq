#include<stdlib.h>

int comp(const void * a, const void * b) {
    return * (int *) a <= * (int *) b;
}

int thirdMax(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comp);
    int cur_max_num = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i ++) {
        if (nums[i] < cur_max_num) {
            cur_max_num = nums[i];
            count ++;
        }

        if (count == 3) {
            return cur_max_num;
        }
    }

    return nums[0];
}
