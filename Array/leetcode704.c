int search(int* nums, int numsSize, int target){
    int front_index = 0;
    int tail_index = numsSize - 1;
    int index = (front_index + tail_index) / 2;
    while (1) {
        if (target < nums[front_index] || target > nums[tail_index]) {
            return -1;
        }

        if (target > nums[index]) {
            front_index = index + 1;
        } else if (target < nums[index]) {
            tail_index = index - 1;
        } else {
            return index;
        }
        int tmp = (front_index + tail_index) / 2;
        if (tmp != index) {
            index = tmp;
        } else {
            return -1;
        }
    }
    return -1;
}
