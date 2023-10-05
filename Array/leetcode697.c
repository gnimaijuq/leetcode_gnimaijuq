// int findShortestSubArray(int* nums, int numsSize){
//     int max_count = 0;
//     int min_length = 1;
//     for (int i = 0; i < numsSize; i ++) {
//         int count = 1;
//         int length = 1;
//         for (int j = i + 1; j < numsSize; j ++) {
//             if (nums[j] == nums[i]) {
//                 count ++;
//                 if (count >= max_count) {
//                     if (count > max_count) {
//                         min_length = 500000;
//                         max_count = count;
//                     }

//                     length = j - i + 1;
//                     min_length = length < min_length ? length : min_length;
//                 }
//             }
//         }

//     }

//     return min_length;
// }

// 官方解答
#include<uthash.h>

struct HashTable {
    int key;
    int num, add1, add2;
    UT_hash_handle hh;
};

int findShortestSubArray(int* nums, int numsSize) {
    struct HashTable * hashTable = NULL;
    for (int i = 0; i < numsSize; i ++) {
        struct  HashTable * tmp;
        HASH_FIND_INT(hashTable, &nums[i], tmp);
        if (tmp != NULL) {
            tmp->num ++;
            tmp->add2 = i;
        } else {
            tmp = (struct HashTable *)malloc(sizeof(struct HashTable));
            tmp->key = nums[i];
            tmp->num = 1;
            tmp->add1 = i;
            tmp->add2 = i;
            HASH_ADD_INT(hashTable, key, tmp);
        }
    }
    int maxNum = 0, minLen = 0;
    struct HashTable * s, * tmp;
    HASH_ITER(hh, hashTable, s, tmp) {
        if (maxNum < s->num) {
            maxNum = s->num;
            minLen = s->add2 - s->add1 + 1;
        } else if (maxNum == s->num) {
            if (minLen > s->add2 - s->add1 + 1) {
                minLen = s->add2 - s->add1 + 1;
            }
        }
    }

    return minLen;
}
