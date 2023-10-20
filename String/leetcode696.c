#include<stdio.h>
#include<string.h>
#include<math.h>

// 超时
// int countBinarySubstrings(char * s){
//     int count = 0;
//     int i = 0;
//     while (i < strlen(s)) {
//         if (s[i] == '0') {
//             // printf("in 1:%d, %c\n", i, s[i]);
//             int count0 = 1;
//             int count1 = 0;
//             int j = i + 1;
//             while (j < strlen(s)) {
//                 if (s[j] == '0') {
//                     count0 ++;
//                 } else {
//                     break;
//                 }
//                 j ++;
//             }
//             int next_i = j;

//             while (j < strlen(s) && count1 < count0) {
//                 if (s[j] == '1') {
//                     count1 ++;
//                 } else {
//                     break;
//                 }
//                 j ++;
//             }

//             // printf("count0: %d, count1: %d, count: %d\n", count0, count1, count);
//             if (count0 == count1) {
//                 count += count0;
//                 i = next_i;
//             } else {
//                 i ++;
//             }
//         } else {
//             // printf("in 2:%d, %c\n", i, s[i]);
//             int count1 = 1;
//             int count0 = 0;
//             int j = i + 1;
//             while (j < strlen(s)) {
//                 if (s[j] == '1') {
//                     count1 ++;
//                 } else {
//                     break;
//                 }
//                 j ++;
//             }
//             int next_i = j;

//             while (j < strlen(s) && count0 < count1) {
//                 if (s[j] == '0') {
//                     count0 ++;
//                 } else {
//                     break;
//                 }
//                 j ++;
//             }

//             // printf("count0: %d, count1: %d, count: %d\n", count0, count1, count);
//             if (count0 == count1) {
//                 count += count1;
//                 i = next_i;
//             } else {
//                 i ++;
//             }
//         }
//     }

//     return count;
// }

// 官方解答
int countBinarySubstrings(char * s) {
    int ptr = 0, n = strlen(s), last = 0, ans = 0;
    while (ptr < n) {
        char c = s[ptr];
        int count = 0;
        while (ptr < n && s[ptr] == c) {
            count ++;
            ptr ++;
        }
        ans += fmin(last, count);
        last = count;
    }
    return ans;
}

int main(int argc, char ** argv) {
    printf("%d\n", countBinarySubstrings("00100"));
    return 0;
}
