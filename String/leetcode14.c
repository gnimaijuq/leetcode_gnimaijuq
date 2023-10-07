#include<string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char * ret = (char *)malloc(sizeof(char) * 200);
    memset(ret, 0, sizeof(char));
    strcpy(ret, strs[0]);

    for (int i = 1; i < strsSize; i ++) {
        for (int j = 0; j <= strlen(strs[i]); j ++) {
            if (strs[i][j] != ret[j]) {
                ret[j] = '\0';
                break;
            }
        }
    }

    return ret;
}
