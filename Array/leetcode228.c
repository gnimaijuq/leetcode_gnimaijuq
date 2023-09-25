/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>

char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    char ** retT = (char *)malloc(sizeof(char *) * numsSize);
    memset(retT, 0, sizeof(char *) * numsSize);
    int index = 0;
    * returnSize = 0;
    int front_index = 0;
    int tail_index = 0;
    long int count = 0;
    for (int i = 0; i < numsSize;) {
        if ((long int)nums[i] - (long int)nums[front_index] == count) {
            i ++;
        } else {
            tail_index = i - 1;
            * returnSize = * returnSize + 1;
            char * temp = malloc(sizeof(char) * 25);
            if (front_index == tail_index) {
                sprintf(temp, "%d", nums[tail_index]);
            } else {
                sprintf(temp, "%d->%d", nums[front_index], nums[tail_index]);
            }
            front_index = ++ tail_index;
            count = 0;
            i = front_index;
            retT[index ++] = temp;
            continue;
        }

        if (i == numsSize) {
            char * temp = malloc(sizeof(char) * 25);
            tail_index = i - 1;
            * returnSize = * returnSize + 1;
            if (count > 0) {
                sprintf(temp, "%d->%d", nums[front_index], nums[tail_index]);
            } else {
                sprintf(temp, "%d", nums[tail_index]);
            }
            retT[index ++] = temp;
        } else {
            count ++;
        }
    }
    return retT;
}
