int missingNumber(int* nums, int numsSize){
    int n = numsSize;
    int sum = (1 + n) * n / 2;
    for (int i = 0; i < numsSize; i ++) {
        sum -= nums[i];
    }
    return sum;
}
