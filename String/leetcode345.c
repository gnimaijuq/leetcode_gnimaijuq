int isNChar(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || \
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        return 1;
    }

    return 0;
}

char * reverseVowels(char * s){
    int length = strlen(s);
    int i = 0, j = length - 1;
    while (i < j) {
        if (isNChar(s[i]) && isNChar(s[j])) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i ++;
            j --;
        } else if (isNChar(s[i]) && ! isNChar(s[j])) {
            j --;
        } else if (!isNChar(s[i]) && isNChar(s[j])) {
            i ++;
        } else {
            i ++;
            j --;
        }
    }

    return s;
}
