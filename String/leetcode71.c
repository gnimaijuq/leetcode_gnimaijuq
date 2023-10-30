// 字符串切割函数，返回一个切割后的数组。
char * * split(const char * s, char delim, int * returnSize) {
    int n = strlen(s);
    char * * ans = (char * *) malloc (sizeof(char *) * n);
    int pos = 0;
    int curr = 0;
    int len = 0;

    while (pos < n) {
        // 先寻找到不为‘/’的字符
        while (pos < n && s[pos] == delim) {
            ++ pos;
        }
        // 计算目录或文件名的起始位置
        curr = pos;
        // 找到目录或文件名的末尾位置
        while (pos < n && s[pos] != delim) {
            ++ pos;
        }
        // 将找到的目录或文件名放入数组中
        if (curr < n) {
            ans[len] = (char *) malloc (sizeof(char) * (pos - curr + 1));
            strncpy(ans[len], s + curr, pos - curr);
            ans[len][pos - curr] = '\0';
            ++ len;
        }
    }

    * returnSize = len;
    return ans;
}

char * simplifyPath(char * path){
    int namesSize = 0;
    int n = strlen(path);
    // 获得一个根据/切割出来的数组
    char * * names = split(path, '/', & namesSize);
    char * * stack = (char * *) malloc (sizeof(char *) * namesSize);
    int stackSize = 0;
    for (int i = 0; i < namesSize; i ++) {
        // 如果是..就返回上一级
        if (!strcmp(names[i], "..")) {
            if (stackSize > 0) {
                -- stackSize;
            }
        } else if (strcmp(names[i], ".")) { // .忽略，不为.则记录到stack中
            stack[stackSize] = names[i];
            ++ stackSize;
        }
    }

    char * ans = (char *) malloc (sizeof(char) * (n + 1));
    int curr = 0;
    if (stackSize == 0) {
        ans[curr] = '/';
        ++ curr;
    } else {
        for (int i = 0; i < stackSize; i ++) {
            ans[curr] = '/';
            ++ curr;
            // 复制到ans的对应位置
            strcpy(ans + curr, stack[i]);
            curr += strlen(stack[i]);
        }
    }
    ans[curr] = '\0';
    for (int i = 0; i < namesSize; i ++) {
        free(names[i]);
    }

    free(names);
    free(stack);

    return ans;
}
