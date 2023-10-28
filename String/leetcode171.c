int titleToNumber(char * columnTitle){
    int n = strlen(columnTitle);
    int ret = 0;
    long long int k = 1;
    for (int i = n - 1; i >= 0; i --) {
        ret += (columnTitle[i] - 'A' + 1) * k;
        k *= 26;
    }

    return ret;
}
