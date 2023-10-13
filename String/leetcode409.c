// 个人解法
// int longestPalindrome(char * s){
//     int a[52];
//     memset(a, 0, 52 * sizeof(int));
//     int n = strlen(s);
//     for (int i = 0; i < n; i ++) {
//         if (s[i] > 'Z') {
//             a[s[i] - 'a' + 26] ++;
//         } else {
//             a[s[i] - 'A'] ++;
//         }
//     }
//     int count = 0;
//     for (int i = 0; i < 52; i ++) {
//         if (a[i] % 2 == 0) {
//             count += a[i];
//         } else {
//             count += a[i] - 1;
//             if (count % 2 == 0) {
//                 count += 1;
//             }
//         }
//     }

//     return count;
// }


// 相同解法下的优化
int longestPalindrome(char * s) {
    int c[128], ret = 0;
    memset(c, 0, sizeof(int) * 128);
    for (int i = 0; i < strlen(s); i ++) {
        c[s[i]] ++;
    }

    for (int i = 0; i < 128; i ++) {
        ret += c[i] - c[i] % 2;
    }

    return ret + (ret != strlen(s));
}
