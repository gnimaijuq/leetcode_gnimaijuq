int removeElement(int* nums, int numsSize, int val){
    int retSize = numsSize;
    int nums_length = numsSize;
    int tmp;
    for (int i = 0; i < nums_length; i ++)
    {
        if (nums[i] == val)
        {
            retSize --;
            for (int j = nums_length - 1; j > i; j --)
            {
                if (nums[j] != val)
                {
                    tmp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = tmp;
                    break;
                }
                nums_length --;
                retSize --;
            }
            nums_length --;
        }
    }

    return retSize;
}

