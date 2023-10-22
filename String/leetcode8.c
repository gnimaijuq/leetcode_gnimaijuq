#include<malloc.h>
#include<string.h>
#include<math.h>

int myAtoi(char * s){
    char * a = (char *) malloc (sizeof(char) * (strlen(s) + 1));
    int index = 0;
    int ret;
    int sign_flag = 1;              // 正
    while (* s == ' ') {
        s ++;
    }
    if (* s <= '0' || * s >= '9') {
        if (* s == '-') {
            sign_flag = 0;
        }
        if (* s == '-' || * s == '+') {
            s ++;
        }
    }

    while (* s >= '0' && * s <= '9') {
        a[index ++] = * s ++;
    }
    a[index] = '\0';
    int n = strlen(a);
    if (n > 10 && a[0] > '0') {
        if (sign_flag) {
            ret = pow(2, 31) - 1;
        } else {
            ret = -1 * pow(2, 31);
        }
    } else {
        long long tmp = 0;
        unsigned long long b = 1;
        for (int i = n - 1; i >= 0; i --) {
            if (i == n - 1) {
                tmp += a[i] - '0';
                continue;
            }
            if (b <= 100000000000000000) {
                b *= 10;
                if (a[i] != '0') {
                    tmp += (a[i] - '0') * b;
                }
            } else {
                if (a[i] != '0') {
                    tmp = pow(2, 31);
                }
            }
        }
        if (sign_flag) {
            if (tmp >= pow(2, 31) - 1) {
                ret = pow(2, 31) - 1;
            } else {
                ret = tmp;
            }
        } else {
            if (tmp >= pow(2, 31)) {
                signed long long c = -1 * pow(2, 31);
                ret = c;
            } else {
                ret = -1 * tmp;
            }
        }
    }
    return ret;
}
