/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>

int comp(const void * a, const void * b) {
    return  * (int *)a <= * (int *)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int mallocSize = nums1Size >= nums2Size ? nums2Size : nums1Size;
    int * retT = (int *)malloc(sizeof(int) * mallocSize);
    * returnSize = 0;
    memset(retT, -1, sizeof(int) * mallocSize);
    for (int i = 0; i < nums1Size; i ++) {
        for (int j = 0; j < nums2Size; j ++) {
            if (nums1[i] == nums2[j]) {
                int tmp = nums1[i] % mallocSize;
                if (retT[tmp] == -1) {
                    * returnSize = * returnSize + 1;
                    retT[tmp] = nums1[i];
                    break;
                } else {
                    while (retT[tmp] != -1 && nums1[i] != retT[tmp]) {
                        tmp++;tmp = tmp % mallocSize;
                    }
                    if (retT[tmp] == -1) {
                        * returnSize = * returnSize + 1;
                        retT[tmp] = nums1[i];
                    }
                    break;
                }
            }
        }
    }

    qsort(retT, mallocSize, sizeof(int), comp);

    return retT;
}
