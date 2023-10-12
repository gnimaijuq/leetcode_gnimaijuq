char findTheDifference(char * s, char * t){
    int a[26];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < strlen(s); i ++) {
        a[s[i] - 'a'] ++;
    }
    for (int i = 0; i < strlen(t); i ++) {
        a[t[i] - 'a'] --;
        if (a[t[i] - 'a'] < 0) {
            return t[i];
        }
    }

    return ' ';
}
