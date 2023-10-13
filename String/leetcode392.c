// bool isSubsequence(char * s, char * t){
//     int flag = 0;
//     int index = 0;
//     for (int i = 0; i < strlen(s); i ++) {
//         for (int j = index; j < strlen(t); j ++) {
//             if (s[i] == t[j]) {
//                 flag = 1;
//                 index = j + 1;
//                 break;
//             }
//         }
//         if (!flag) {
//             return false;
//         }
//         flag = 0;
//     }
//     return true;
// }

// 官方解答
bool isSubsequence(char * s, char * t) {
    int n = strlen(s), m = strlen(t);
    int i = 0, j = 0;
    while(i < n && j < m) {
        if (s[i] == t[j]) {
            i ++;
        }

        j ++;
    }

    return i == n;
}
