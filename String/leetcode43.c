#include<string.h>
#include<malloc.h>
#include<stdio.h>

char * multiply(char * num1, char * num2) {
    int length1 = strlen(num1);
    int length2 = strlen(num2);
    int totalLength = length1 + length2;
    char * ret = calloc(totalLength + 1, sizeof(char));
    int * value = (int *) malloc (sizeof(int) * totalLength);
    memset(value, 0, sizeof(int) * totalLength);
    for (int i = length1 - 1; i >= 0; i --) {
        for (int j = length2 - 1; j >= 0; j --) {
            value[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    for (int i = totalLength - 1; i > 0; i --) {
        value[i - 1] += value[i] / 10;
        value[i] %= 10;
    }

    int index = 0;
    int i = 0;
    while (!value[i] && i < totalLength - 1) {  // 忽略0，但最高位的0不能忽略，此时的结果为0
        i ++;
    }
    for (; i < totalLength; i ++) {
        ret[index ++] = value[i] + '0';
    }

    free(value);

    return ret;
}

int main(int argc, char ** argv) {
    char * res = multiply("9", "9");
    printf("%s\n", res);
    return 0;
}
