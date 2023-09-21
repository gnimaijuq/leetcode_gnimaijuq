int removeDuplicates(int* nums, int numsSize){
    int k = 1;
    for(int i = 0; i < numsSize; i ++)
    {
        for(int j = i + 1; j < numsSize; j ++)
        {
            if (nums[i] < nums[j])
            {
                nums[i + 1] = nums[j];
                k ++;
                break;
            }

            if (j == numsSize - 1 && nums[i] == nums[j])
            {
                return k;
            }
        }
    }
    return k;
}
