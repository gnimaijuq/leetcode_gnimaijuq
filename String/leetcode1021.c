char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    char * res = (char *) calloc (n + 1, sizeof(char));
    int pos = 0;
    int level = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') {
            if (level > 0) {
                res[pos ++] = s[i];
            }
            level ++;
        } else {
            level --;
            if (level > 0) {
                res[pos ++] = s[i];
            }
        }
    }

    return res;
}
