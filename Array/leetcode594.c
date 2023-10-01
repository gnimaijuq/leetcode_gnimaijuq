#include<stdlib.h>

int comp(const void * a, const void * b) {
    return * (int *) a >= * (int *) b;
}

int findLHS(int* nums, int numsSize){
    int max_length = 0;
    int length = 0;
    int front = 0;
    int check_max_flag = 0;

    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize; i ++) {
        if (i == 0 || nums[i] != front) {
            front = nums[i];
        }
        for (int j = i + 1; j < numsSize; j ++) {
            if (nums[j] - front <= 1) {
                length = length == 0 ? 2 : length + 1;
                if (nums[j] - front == 1) {
                    check_max_flag = 1;
                }
            } else {
                break;
            }
            if (length > max_length && check_max_flag) {
                max_length = length;
            }
        }
        length = 0;
        check_max_flag = 0;
    }
    return max_length;
}
