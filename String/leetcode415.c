char * addStrings(char * num1, char * num2){
    int n = strlen(num1), m = strlen(num2);
    int malloc_size = (m > n ? m : n) + 2;
    char * retS = (char *) malloc (sizeof(char) * malloc_size);
    memset(retS, '\0', sizeof(char) * malloc_size);
    int index = malloc_size - 2;
    int flag = 0;
    while (n > 0 || m > 0) {
        char a = n > 0 ? num1[-- n] : '0';
        char b = m > 0 ? num2[-- m] : '0';
        retS[index --] = a + b + flag - '0' > '9' ? \
                        a + b + flag - '0' - 10 : \
                        a + b + flag - '0';
        flag = a + b + flag - '0' > '9' ? 1 : 0;
    }

    if (flag) {
        retS[index] = '1';
    } else {
        index ++;
    }

    if (retS[0] == '\0') {
        for (int i = 0; i < malloc_size - 1 && index < malloc_size; i ++) {
            retS[i] = retS[index ++];
        }
    }

    return retS;
}
