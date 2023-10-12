#include<string.h>
#include<stdio.h>

bool wordPattern(char * pattern, char * s){
    char a[301][3001];
    char * p = strtok(s, " ");
    int pos = 0, len = strlen(pattern);
    while (p != NULL) {
        sprintf(a[pos ++], "%s", p);
        p = strtok(NULL, " ");
    }

    if (len != pos) {
        return false;
    }

    for (int i = 0; i < len; i ++) {
        for (int j = i + 1; j < len; j ++) {
            int re = strcmp(a[i], a[j]);
            if (pattern[i] == pattern[j] && re != 0 || \
                pattern[i] != pattern[j] && re == 0) {
                    return false;
                }
        }
    }
    return true;
}
