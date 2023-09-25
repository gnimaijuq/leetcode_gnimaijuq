// 超时
// bool containsNearbyDuplicate(int* nums, int numsSize, int k){
//     for (int i = 0; i < numsSize; i ++) {
//         for(int j = i + 1; j < numsSize && j <= i + k; j ++) {
//             if (nums[i] == nums[j]) {
//                 return true;
//             }
//         }
//     }

//     return false;
// }

// 评论区题解(hash),依然超时。
bool containsNearbyDuplicate (int * nums, int numsSize, int k) {
    if (numsSize == 0) {
        return false;
    }

    int * mark = (int *)malloc(sizeof(int) * numsSize);
    memset(mark, -1, sizeof(int) * numsSize);
    int tmp;

    for (int i = 0; i < numsSize; i ++) {
        tmp = nums[i] % numsSize;
        if (tmp < 0) {
            tmp += (numsSize - 1);
        }
        if (mark[tmp] == -1) {
            mark[tmp] = i;
        } else {
            while (nums[mark[tmp]] != nums[i]) {
                // tmp = (nums[mark[tmp]] + 1) % numsSize;
                tmp ++;
                tmp %= numsSize;
                if (mark[tmp] == -1) {
                    mark[tmp] = i;
                }
            }

            if (i != mark[tmp]) {
                if (i - mark[tmp] <= k) {
                    return true;
                } else {
                    mark[tmp] = i;
                }
            }
        }
    }

    return false;
}
