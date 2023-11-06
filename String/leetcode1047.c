char* removeDuplicates(char* s) {
    int n = strlen(s);
    char * res = (char *) calloc (n + 1, sizeof(char));
    int stack_top = 0;
    for (int i = 0; i < n; i ++) {
        if (stack_top == 0) {
            res[stack_top ++] = s[i];
        } else {
            if (res[stack_top - 1] == s[i]) {
                stack_top --;
                res[stack_top] = '\0';
            } else {
                res[stack_top ++] = s[i];
            }
        }
    }

    return res;
}
