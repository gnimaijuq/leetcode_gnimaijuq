void moveZeroes(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i ++) {
        int index = 1;
        while (!nums[i] && i + index < numsSize) {
            nums[i] |= nums[i + index];
            index ++;
        }

        if (i + (-- index) < numsSize && nums[i]) {
            if (index) {
                nums[i + index] = 0;
            }
        } else {
            break;
        }
    }
}
