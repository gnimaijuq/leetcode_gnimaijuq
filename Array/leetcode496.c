/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int * retT = (int *)malloc(sizeof(int) * nums1Size);
    * returnSize = nums1Size;
    int index = 0;
    int target = -1;

    for (int i = 0; i < nums1Size; i ++) {
        if (nums1[i] == nums2[nums2Size - 1]) {
            retT[index ++] = -1;
            continue;
        }
        for (int j = 0; j < nums2Size; j ++) {
            if (target != -1) {
                if (nums2[j] <= target) {
                    if (j != nums2Size - 1) {
                        continue;
                    } else {
                        retT[index ++] = -1;
                        break;
                    }
                }
                retT[index ++] = nums2[j];
                break;
            }

            if (nums1[i] == nums2[j]) {
                target = nums2[j];
            }
        }

        target = -1;
    }

    return retT;
}
