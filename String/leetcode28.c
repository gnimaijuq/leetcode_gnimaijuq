#include<string.h>

int strStr(char * haystack, char * needle){
    int n = strlen(haystack), m = strlen(needle);
    for (int i = 0; i < n; i ++) {
        if (haystack[i] != * needle) {
            continue;
        }
        int flag = 1;
        for (int j = 0; j < m; j ++) {
            if (haystack[i + j] != needle[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}
