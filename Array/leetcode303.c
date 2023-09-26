#include <stdio.h>

typedef struct {
    int * nums;
    int numsSize;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray * ret = (NumArray *)malloc(sizeof(NumArray));
    if (nums && numsSize) {
        ret->nums = malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i ++) {
            ret->nums[i] = nums[i];
        }
    } else {
        ret->nums = NULL;
    }

    ret->numsSize = numsSize;

    return ret;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if (!obj) {
        return 0;
    }

    int sum = 0;
    for(int i = left; i <= right; i ++) {
        sum += obj->nums[i];
    }

    return sum;
}

void numArrayFree(NumArray* obj) {
    if (obj) {
        if (obj->nums) {
            free(obj->nums);
        }
        free(obj);
    }
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
