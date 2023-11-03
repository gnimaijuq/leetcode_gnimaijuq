char * reverseOnlyLetters(char * s){
    int n = strlen(s);
    char * ans = (char *) calloc (n + 1, sizeof(char));
    int j = n - 1;
    for (int i = 0; i < n; i ++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            while (!(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= 'A' && s[j] <= 'Z')) {
                j --;
            }
            if (j >= 0) {
                ans[i] = s[j];
                j --;
            }
        } else {
            ans[i] = s[i];
        }
    }

    return ans;
}
