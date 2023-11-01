/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 他人题解
int isValid(char * s, int i, int j) {
    if (i > j) return 0;
    if (s[i] == '0' && i != j) {            // 0开头的数字不合法
        return 0;
    }
    int num = 0;
    for (; i <= j; i ++) {
        if (s[i] > '9' || s[i] < '0') {     // 遇到非数字字符不合法
            return 0;
        }
        num = num * 10 + (s[i] - '0');
        if (num > 255) {                    // 如果大于255了不合法
            return 0;
        }
    }
    return 1;
}

void dfs(char * s, char * * ans, int * returnSize, char * path, int path_i, int index, int len, int n) {
    if (n == 3) {                           // .号个数为三，只需要判断剩余子串是否满足要求
        if (isValid(s, index, len - 1)) {   // 满足条件的有效子串组合
            strncpy(path + path_i, s + index, len - index);
            ans[(* returnSize)] = (char *) malloc (sizeof(char) * (len + 4));
            memcpy(ans[(* returnSize)], path, sizeof(char) * (len + 4));
            (* returnSize) ++;
        }
        return;
    }

    for (int i = index; i < len && i - index < 3; i ++) {       // 枚举有可能的分割点，剪枝 i - index < 3，数值最多三位
        if(isValid(s, index, i)) {                              // 进一步剪枝，如果子串不满足条件，那么之后不管怎么分割，整个组合都是不满足，提前结束
            strncpy(path + path_i, s + index, i - index + 1);
            path[path_i + i - index + 1] = '.';
            dfs(s, ans, returnSize, path, path_i + i - index + 2, i + 1, len, n + 1);
        } else
            break;
    }

    return;
}

char ** restoreIpAddresses(char * s, int* returnSize) {
    char * * ans = (char * *) malloc (sizeof(char *) * 3000);
    * returnSize = 0;
    int len = strlen(s);
    char path[len + 4];
    path[len + 3] = '\0';
    dfs(s, ans, returnSize, path, 0, 0, len, 0);
    return ans;
}
