// int singleNumber(int* nums, int numsSize){
//     int single_number;
//     int is_find = 1;
//     for (int i = 0; i < numsSize; i ++) {
//         is_find = 1;
//         for (int j = 0; j < numsSize; j ++) {
//             if (j != i) {
//                 if (nums[j] == nums[i]) {
//                     is_find = 0;
//                     break;
//                 }
//             }
//         }

//         if (is_find) {
//             single_number = nums[i];
//             break;
//         }
//     }

//     return single_number;
// }

// 官方解答
int singleNumber (int * nums, int numsSize) {
    int single_numder = 0;
    for (int i = 0; i < numsSize; i ++) {
        single_numder ^= nums[i];
    }
    return single_numder;
}
