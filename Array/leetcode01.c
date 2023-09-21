/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int * retArray = malloc(sizeof(int) * 2);
    * returnSize = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        for (int j = i + 1; j < numsSize; j ++)
        {
            if (nums[i] + nums[j] == target)
            {
                retArray[0] = i;
                retArray[1] = j;
                * returnSize = 2;
                return retArray;
            }
        }
    }

    return retArray;
}
