#include<string.h>
int lengthOfLastWord(char * s){
    int length = 0;
    int m = strlen(s) - 1;
    while (s[m --] == ' ');
    for (m = m + 1; m >= 0; m --) {
        if(s[m] != ' ') {
            length ++;
        } else {
            return length;
        }
    }
    return length;
}
