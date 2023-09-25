// 超时
// bool containsDuplicate(int* nums, int numsSize){
//     for (int i = 0; i < numsSize; i ++) {
//         for (int j = 0; j < numsSize; j ++) {
//             if (i != j && nums[i] == nums[j]) {
//                 return true;
//             }
//         }
//     }

//     return false;
// }
#include<stdlib.h>

int comp(int * a, int * b) {
    if (* a >= * b) {
        return 1;
    }

    return 0;
}

bool containsDuplicate (int * nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 1; i ++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}


