char * toLowerCase(char * s){
    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] < 'a' && s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 'a' - 'A';
        }
    }

    return s;
}
