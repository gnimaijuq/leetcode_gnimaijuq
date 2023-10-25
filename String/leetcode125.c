#include<string.h>

bool isPalindrome(char * s) {
    int right = strlen(s) - 1;
    int left = 0;
    char c = 'a' - 'A';
    while (left < right) {
        if (s[left] == s[right]) {
            left ++;
            right --;
        } else if ((s[left] - s[right] == c || s[right] - s[left] == c) && \
                ((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z')) && \
                ((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z'))) {
            left ++;
            right --;
        } else {
            if (!(s[left] >= 'a' && s[left] <= 'z') && !(s[left] >= 'A' && s[left] <= 'Z') && !(s[left] >= '0' && s[left] <= '9')) {
                left ++;
                continue;
            } else if (!(s[right] >= 'a' && s[right] <= 'z') && !(s[right] >= 'A' && s[right] <= 'Z') && !(s[right] >= '0' && s[right] <= '9')) {
                right --;
                continue;
            }

            return false;
        }
    }

    return true;
}
