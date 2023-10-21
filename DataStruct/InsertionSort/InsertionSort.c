#include<stdio.h>

void swap(int * a, int * b) {
    int tmp = * a;
    * a = * b;
    * b = tmp;
}

// 原版本
// void InsertionSort(int * nums, int numsSize) {
//     for (int i = 1; i < numsSize; i ++) {
//         for (int j = i; j - 1>= 0; j --) {
//             if (nums[j] < nums[j - 1]) {
//                 swap(& nums[j], & nums[j - 1]);
//             } else {
//                 break;
//             }
//         }
//     }
// }

// void InsertionSort(int * nums, int numsSize) {
//     for (int i = numsSize - 1; i >= 0; i --) {
//         int tmp = nums[i];
//         int j;
//         for (j = i; j + 1 < numsSize && tmp > nums[j + 1]; j ++) {
//             nums[j] = nums[j + 1];
//         }
//         nums[j] = tmp;
//     }
// }

// 优化版
void InsertionSort(int * nums, int numsSize) {
    for (int i = 0; i < numsSize; i ++) {
        int tmp = nums[i];
        int j;
        for (j = i; j - 1 >= 0 & tmp < nums[j - 1]; j --) {
            nums[j] = nums[j - 1];
        }
        nums[j] = tmp;
    }
}

int main(int argc, char ** argv) {
    int a[] = {6,5,3,2,4,1};
    InsertionSort(a, 6);
    for (int i = 0; i < 6; i ++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
