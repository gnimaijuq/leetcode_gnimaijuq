#include<string.h>

static int Roman2IntBySingle(char s);

int romanToInt(char * s){
    int ret = 0;
    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] == 'I') {
            i ++;
            if (i < strlen(s)) {
                if (s[i] != 'V' && s[i] != 'X') {
                    ret += 1;
                    i --;
                } else if (s[i] == 'V' || s[i] == 'X') {
                    ret += Roman2IntBySingle(s[i]) - 1;
                }
            } else {
                ret += 1;
            }
            continue;
        } else if (s[i] == 'X') {
            i ++;
            if (i < strlen(s)) {
                if (s[i] != 'L' && s[i] != 'C') {
                    ret += 10;
                    i --;
                } else if (s[i] == 'L' || s[i] == 'C') {
                    ret += Roman2IntBySingle(s[i]) - 10;
                }
            } else {
                ret += 10;
            }
            continue;
        } else if (s[i] == 'C') {
            i ++;
            if (i < strlen(s)) {
                if (s[i] != 'D' && s[i] != 'M') {
                    ret += 100;
                    i --;
                } else if (s[i] == 'D' || s[i] == 'M') {
                    ret += Roman2IntBySingle(s[i]) - 100;
                }
            } else {
                ret += 100;
            }
            continue;
        } else {
            ret += Roman2IntBySingle(s[i]);
        }
    }
    return ret;
}

static int Roman2IntBySingle(char s) {
    switch (s)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return 0;
    }
}
