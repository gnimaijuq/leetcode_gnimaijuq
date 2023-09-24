// int majorityElement(int* nums, int numsSize){
//     int count = 0;
//     int majority_element = nums[0];
//     for (int i = 0; i < numsSize; i ++) {
//         if (majority_element != nums[i]) {
//             majority_element = nums[i];
//         } else if (i != 0) {
//             continue;
//         }

//         for (int j = 0; j < numsSize; j ++) {
//             if (majority_element == nums[j]) {
//                 count ++;
//             }

//             if (count > numsSize / 2) {
//                 break;
//             }
//         }

//         if (count > numsSize / 2) {
//             break;
//         }

//         count = 0;
//     }

//     return majority_element;
// }

// 官方：Boyer-Moore 算法
int majorityElement(int* nums, int numsSize) {
    int winner = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i ++) {
        if (count == 0) {
            winner = nums[i];
        }

        count += winner == nums[i] ? 1 : -1;
    }

    return winner;
}
