char * reverseWords(char * s){
    char * retS = (char *) malloc (sizeof(char) * (strlen(s) + 1));
    memset(retS, 0, sizeof(char) * (strlen(s) + 1));
    int front_i = 0;
    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] == ' ') {
            int j = i - 1;
            while (front_i <= j) {
                retS[j] = s[front_i];
                retS[front_i] = s[j];
                front_i ++;
                j --;
            }
            retS[i] = ' ';
            front_i = i + 1;
        }
    }
    int j = strlen(s) - 1;
    while (front_i <= j) {
        retS[j] = s[front_i];
        retS[front_i] = s[j];
        front_i ++;
        j --;
    }
    return retS;
}
