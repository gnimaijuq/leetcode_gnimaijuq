#include<string.h>

char getPair(char c) {
    if (c == '}') {
        return '{';
    } else if (c == ']') {
        return '[';
    } else {
        return '(';
    }
}

bool isValid(char * s){
    if (strlen(s)%2 != 0) {
        return false;
    }
    char * tmp = malloc(sizeof(char) * (strlen(s) + 1));
    int stack_top = 0;
    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] != '}' && s[i] != ']' && s[i] != ')') {
            tmp[stack_top ++] =  s[i];
        } else {
            if (stack_top == 0) {
                return false;
            } else {
                char c = getPair(s[i]);
                if (tmp[-- stack_top] != c) {
                    return false;
                }
            }
        }
    }
    free(tmp);

    if (stack_top != 0) {
        return false;
    }

    return true;
}
