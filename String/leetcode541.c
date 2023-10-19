char * reverseStr(char * s, int k) {
    // char * retS = (char *) malloc (sizeof(char) * (strlen(s) + 1));
    // memset(retS, 0, sizeof(char) * (strlen(s) + 1));
    for (int i = 0; i < strlen(s); i += 2 * k) {
        int n = i + k >= strlen(s) ? strlen(s) - 1 : i + k - 1;
        int j = i;
        while (j <= n) {
            int tmp = s[n];
            s[n] = s[j];
            s[j] = tmp;
            // retS[j] = s[n];
            // retS[n] = s[j];
            j ++;
            n --;
        }
        // for (int a = i + k; a < i + 2 * k && a < strlen(s); a ++) {
        //     retS[a] = s[a];
        // }
    }
    // return retS;
    return s;
}
