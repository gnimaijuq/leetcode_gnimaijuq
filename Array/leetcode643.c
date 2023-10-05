// double findMaxAverage(int* nums, int numsSize, int k){
//     int sum = 0;
//     for (int i = 0; i < k; i ++) {
//         sum += nums[i];
//     }
//     double max_average = (double)sum / k;
//     int front_i = 0, tail_i = k - 1;
//     for (int i = k; i < numsSize; i = tail_i + 1) {
//         if (nums[i] >= nums[front_i]) {
//             front_i ++;
//             tail_i ++;

//             if (tail_i == numsSize - 1) {
//                 double average = 0;
//                 sum = 0;
//                 for (int j = front_i; j <= tail_i; j ++) {
//                     sum += nums[j];
//                 }
//                 average = (double)sum / k;
//                 if (average > max_average) {
//                     max_average = average;
//                 }
//             }

//         } else {
//             double average = 0;
//             sum = 0;
//             for (int j = front_i; j <= tail_i; j ++) {
//                 sum += nums[j];
//             }
//             average = (double)sum / k;
//             if (average > max_average) {
//                 max_average = average;
//             }
//             front_i += 2;
//             tail_i += 2;
//         }
//     }
//     return max_average;
// }


// 官方解答
#include<math.h>

double findMaxAverage(int * nums, int numsSize, int k) {
    int sum = 0;
    for (int i = 0; i < k; i ++) {
        sum += nums[i];
    }
    int MaxSum = sum;
    for (int i = k; i < numsSize; i ++) {
        sum = sum + nums[i] - nums[i - k];
        MaxSum = fmax(sum, MaxSum);
    }

    return (double)MaxSum / k;
}
