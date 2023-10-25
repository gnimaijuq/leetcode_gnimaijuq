#include<malloc.h>
#include<string.h>
#include<stdio.h>

#define MAX_SIZE 10000

int len;

char * ret;
char * tmp;

char * countAndSay(int n){
    if (n == 1) {
        ret = (char *) malloc (sizeof(char) * MAX_SIZE);
        memset(ret, 0, sizeof(char) * MAX_SIZE);
        ret[0] = '1';
        return ret;
    }

    tmp = (char *) calloc (MAX_SIZE, sizeof(char));
    strcpy(tmp, countAndSay(n - 1));
    memset(ret, 0, sizeof(char) * MAX_SIZE);
    printf("tmp: %s\n" , tmp);
    char num = tmp[0];
    int count = 1;
    if (strlen(tmp) == 1) {
        sprintf(ret, "%d%c", count, num);
        return ret;
    }

    for (int i = 1; i < strlen(tmp); i ++) {
        if (num != tmp[i]) {
            sprintf(ret, "%s%d%c", ret, count, num);
            num = tmp[i];
            count = 1;
        } else {
            count ++;
        }

        if (i == strlen(tmp) - 1) {
            sprintf(ret, "%s%d%c", ret, count, num);
        }
    }
    printf("ret: %s\n", ret);
    return ret;
}

int main(int argc, char ** argv) {
    char * res = countAndSay(16);
    printf("out:%s\n", res);
    printf("ret:%s\n", ret);
    return 0;
}
