/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<string.h>
#include<malloc.h>

int* shortestToChar(char * s, char c, int* returnSize){
    int n = strlen(s);
    * returnSize = n;
    int * ans = (int *) malloc (sizeof(int) * n);
    for (int i = 0; i < n; i ++) {
        if (s[i] == c) {
            ans[i] = 0;
        } else {
            ans[i] = 10000;
        }
    }

    for (int i = 0; i < n; i ++) {
        if (ans[i] == 0) {
            for (int j = 0; j < n; j ++) {
                if (j != i) {
                    if (i - j > 0 && i - j < ans[j]) {
                        ans[j] = i - j;
                    } else if (j - i > 0 && j - i < ans[j]) {
                        ans[j] = j - i;
                    }
                }
            }
        }
    }

    return ans;
}


int main(int argc, char * * argv) {
    int returnSize;
    int * a = shortestToChar("loveleetcode", 'e', & returnSize);
    for (int i = 0; i < returnSize; i ++) {
        printf("out: %d\n", a[i]);
    }
    return 0;
}
