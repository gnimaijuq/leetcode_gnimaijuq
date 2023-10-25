bool rotateString(char * s, char * goal){
    int n = strlen(s);
    int m = strlen(goal);
    if (n != m) {
        return false;
    }
    int flag = 1;
    for (int i = 0; i < n; i ++) {
        if (s[i] == goal[0]) {
            int index = i;
            flag = 1;
            for (int j = 0; j < m; j ++) {
                if (s[index] == goal[j]) {
                    index = index + 1 < n ? index + 1 : 0;
                } else {
                    flag = 0;
                    break;
                }
            }

            if (flag) {
                return true;
            }
        }
    }

    return false;
}
