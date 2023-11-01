bool backspaceCompare(char * s, char * t){
    int n = strlen(s);
    int m = strlen(t);
    char * stack_a = (char *) malloc (sizeof(char) * (n + 1));
    int stack_a_size = 0;
    char * stack_b = (char *) malloc (sizeof(char) * (m + 1));
    int stack_b_size = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '#') {
            if (stack_a_size != 0) {
                stack_a_size --;
            }
            continue;
        }

        stack_a[stack_a_size ++] = s[i];
    }
    stack_a[stack_a_size] = '\0';

    for (int i = 0; i < m; i ++) {
        if (t[i] == '#') {
            if (stack_b_size != 0) {
                stack_b_size --;
            }
            continue;
        }

        stack_b[stack_b_size ++] = t[i];
    }
    stack_b[stack_b_size] = '\0';

    if (!strcmp(stack_a, stack_b)) {
        free(stack_a);
        free(stack_b);
        return true;
    }

    free(stack_a);
    free(stack_b);
    return false;
}
