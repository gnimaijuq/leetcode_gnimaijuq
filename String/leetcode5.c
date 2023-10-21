#include<string.h>
#include<math.h>

int expandAroundCenter(char * s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < strlen(s) && s[L] == s[R]) {
        // 计算以left和right为中心的回文串长度
        L --;
        R ++;
    }
    return R - L - 1;
}

char * longestPalindrome(char * s){
    if (strlen(s) < 1) {
        return "";
    }

    int start = 0, end = 0;
    for (int i = 0; i < strlen(s); i ++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = fmax(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }

    s[end + 1] = '\0';

    return & s[start];
}
