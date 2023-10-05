#include<stdio.h>
#define CHANGE_P_TYPE(type, a) (#type *)a
#define TYPE(type) #type

static int search(int * nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char ** argv) {
    int data[8] = {24, 18, 12, 9, 16, 66, 32, 4};
    int ret_index = search(data, 8, 32);
    printf("the return index : %d\n", ret_index);
    return 0;
}
