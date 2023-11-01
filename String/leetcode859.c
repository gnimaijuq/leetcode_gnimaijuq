bool buddyStrings(char * s, char * goal){
    int n = strlen(s);
    int m = strlen(goal);
    if (n != m) {
        return false;
    }

    if (!strcmp(s, goal)) {
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if (s[i] == s[j]) {
                    return true;
                }
            }
        }
    }

    int first = -1;
    int second = -1;
    for (int i = 0; i < n; i ++) {
        if (s[i] != goal[i]) {
            if (first == -1) {
                first = i;
            } else if (second == -1) {
                second = i;
                break;
            }
        }
    }

    if (first == -1 || second == -1) {
        return false;
    }

    char tmp = s[first];
    s[first] = s[second];
    s[second] = tmp;

    if (!strcmp(s, goal)) {
        return true;
    }

    return false;
}
