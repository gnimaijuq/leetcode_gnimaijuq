void reverseString(char* s, int sSize){
    int i = 0;
    int j = sSize - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i ++;
        j --;
    }
}
