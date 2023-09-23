int searchInsert(int* nums, int numsSize, int target){
    int front = 0;
    int tail = numsSize;
    int index = (front + tail) / 2;

    while(numsSize)
    {
        if (nums[index] < target) {
            front = index;
        } else if (nums[index] > target) {
            tail = index;
        } else {
            return index;
        }

        index = (front + tail) / 2;
        numsSize /= 2;
    }

    if (nums[index] < target) {
        index++;
    }

    return index;
}
