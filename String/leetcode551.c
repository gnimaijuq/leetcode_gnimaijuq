bool checkRecord(char * s){
    int A_count = 0;
    int L_count = 0;
    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] == 'A') {
            L_count = 0;
            A_count ++;
        } else if (s[i] == 'L') {
            L_count ++;
            if (L_count == 3) {
                break;
            }
        } else {
            L_count = 0;
        }
    }

    if (A_count >= 2 || L_count >= 3) {
        return false;
    }

    return true;
}
