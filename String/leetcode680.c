#include <string.h>
#include <stdio.h>

int validPalindrome(char * s){
    int is_del_ok = 0;
    int front_i = 0;
    int tail_i = strlen(s) - 1;
    while (front_i <= tail_i) {
        // printf("cur:%d %d\n", front_i, tail_i);
        // printf("cur:%c %c\n", s[front_i], s[tail_i]);
        if (s[front_i] == s[tail_i]) {
            front_i ++;
            tail_i --;
        } else {
            if (is_del_ok || (s[front_i + 1] != s[tail_i] && s[front_i] != s[tail_i - 1])) {
                // printf("out:%d %d\n", front_i, tail_i);
                // printf("out:%c %c\n", s[front_i], s[tail_i]);
                return 0;
            }

            if (s[front_i + 1] == s[tail_i] && s[front_i] == s[tail_i - 1]) {
                front_i ++;
                tail_i --;
                continue;
            }

            if (s[front_i + 1] == s[tail_i] && s[front_i] != s[tail_i - 1]) {
                front_i ++;
            } else if (s[front_i] == s[tail_i - 1] && s[front_i + 1] != s[tail_i]) {
                tail_i --;
            }

            is_del_ok = 1;
        }
    }
    // printf("out:%d %d\n", front_i, tail_i);
    // printf("out:%c %c\n", s[front_i], s[tail_i]);

    return 1;
}

int main(int argc, char * * argv) {
    printf("%d", validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"));
    return 0;
}
