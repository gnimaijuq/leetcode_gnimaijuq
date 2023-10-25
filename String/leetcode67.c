#include<string.h>
char * addBinary(char * a, char * b){
    int m = strlen(a) - 1, n = strlen(b) - 1;
    int malloc_size = m > n ? m + 3 : n + 3;
    char * retStr = (char *) malloc (sizeof(char) * malloc_size);
    memset(retStr, 0, sizeof(char) * malloc_size);
    int index = malloc_size - 2;
    int flag = 0;
    while (m >= 0 || n >= 0) {
        char s1;
        char s2;
        if (m >= 0 && n >= 0) {
            s1 = a[m --];
            s2 = b[n --];
        } else if (m >= 0 && n < 0) {
            s1 = a[m --];
            s2 = '0';
        } else if (m < 0 && n >= 0) {
            s1 = '0';
            s2 = b[n --];
        }
        retStr[index --] = s1 + s2 + flag - '0' > '1' ? \
                            s1 + s2 + flag - '2' : \
                            s1 + s2 + flag - '0';
        flag = s1 + s2 + flag - '0' > '1' ? 1 : 0;
    }
    if (flag) {
        retStr[index] = '1';
    } else {
        index ++;
    }

    if (retStr[0] == '\0') {
        for (int i = 0; i < malloc_size - 1 && index < malloc_size; i ++) {
            retStr[i] = retStr[index ++];
        }
    }

    return retStr;
}
