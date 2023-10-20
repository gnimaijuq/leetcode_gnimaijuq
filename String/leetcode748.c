#include<stdio.h>
#include<string.h>


char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    int a[26];
    memset(a, -1, sizeof(int) * 26);
    for (int i = 0; i < strlen(licensePlate); i ++) {
        if (licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') {
            if (a[licensePlate[i] - 'A'] == -1) {
                a[licensePlate[i] - 'A'] = 0;
            }
            a[licensePlate[i] - 'A'] ++;
        }

        if (licensePlate[i] >= 'a' && licensePlate[i] <= 'z') {
            if (a[licensePlate[i] - 'a'] == -1) {
                a[licensePlate[i] - 'a'] = 0;
            }
            a[licensePlate[i] - 'a'] ++;
        }
    }
    // for (int i = 0; i < 26; i ++) {
    //     printf("%d,", a[i]);
    // }
    // printf("\n");

    int min_length = 16;
    int min_i = -1;
    for (int i = 0; i < wordsSize; i ++) {
        // printf("%s\n", words[i]);
        int n = strlen(words[i]);
        int b[26];
        memset(b, -1, sizeof(int) * 26);
        for (int j = 0; j < n; j ++) {
            if (words[i][j] >= 'A' && words[i][j] <= 'Z') {
                if (a[words[i][j] - 'A'] != -1) {
                    if (b[words[i][j] - 'A'] == -1) {
                        b[words[i][j] - 'A'] = a[words[i][j] - 'A'] - 1;
                    } else if (b[words[i][j] - 'A'] != 0) {
                        b[words[i][j] - 'A'] --;
                    }
                    // printf("%c, %d\n", words[i][j], b[words[i][j] - 'A']);
                }
            }

            if (words[i][j] >= 'a' && words[i][j] <= 'z') {
                if (a[words[i][j] - 'a'] != -1) {
                    if (b[words[i][j] - 'a'] == -1) {
                        b[words[i][j] - 'a'] = a[words[i][j] - 'a'] - 1;
                    } else if (b[words[i][j] - 'a'] != 0) {
                        b[words[i][j] - 'a'] --;
                    }
                    // printf("%c, %d\n", words[i][j], b[words[i][j] - 'a']);
                }
            }
        }

        int flag = 1;
        for (int i = 0; i < 26; i ++) {
            // printf("%d,", b[i]);
            if (a[i] != -1 && b[i] != 0) {
                flag = 0;
                break;
            }
        }
        // printf("\n");
        if (flag) {
            if (n < min_length) {
                min_length = n;
                min_i = i;
            }
        }
    }
    if (min_i == -1) {
        return NULL;
    }

    return words[min_i];
}


int main(int argc, char ** argv) {
    char * argv1[] = {"measure","other","every","base","according","level","meeting","none","marriage","rest"};
    char * ret = shortestCompletingWord("GrC8950", argv1, 10);
    printf("ret: %s\n", ret);
    return 0;
}
