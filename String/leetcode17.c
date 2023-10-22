/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<string.h>
#include<malloc.h>

// const char * a[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

// char ** letterCombinations(char * digits, int* returnSize){
//     int n = strlen(digits);
//     // printf("strlen(digits) : %ld\n", strlen(digits));
//     * returnSize = n > 0 ? 1 : 0;
//     for (int i = 0; i < strlen(digits); i ++) {
//         // printf("strlen(a[b[digits[i] - '0']]) : %ld\n", strlen(a[b[digits[i] - '0']]));
//         (* returnSize) *= strlen(a[digits[i] - '0']);
//     }
//     char ** ret = (char **) malloc (sizeof(char *) * (* returnSize));
//     int index = 0;
//     char * tmp;
//     tmp = (char *) malloc(sizeof(char) * (n + 1));
//     memset(tmp, 0, n + 1);
//     if (n > 0) {
//         int n0 = strlen(a[digits[0] - '0']);
//         for (int i = 0; i < n0; i ++) {
//             sprintf(tmp, "%c", a[digits[0] - '0'][i]);
//             // printf("1:%s\n", tmp);
//             if (n > 1) {
//                 int n1 = strlen(a[digits[1] - '0']);
//                 for (int j = 0; j < n1; j ++) {
//                     sprintf(tmp, "%c", a[digits[0] - '0'][i]);
//                     sprintf(tmp, "%s%c", tmp, a[digits[1] - '0'][j]);
//                     // printf("2:%s\n", tmp);
//                     if (n > 2) {
//                         int n2 = strlen(a[digits[2] - '0']);
//                         for (int k = 0; k < n2; k ++) {
//                             sprintf(tmp, "%c%c", a[digits[0] - '0'][i], a[digits[1] - '0'][j]);
//                             sprintf(tmp, "%s%c", tmp, a[digits[2] - '0'][k]);
//                             // printf("3:%s\n", tmp);
//                             if (n > 3) {
//                                 int n3 = strlen(a[digits[3] - '0']);
//                                 for (int l = 0; l < n3; l ++) {
//                                     sprintf(tmp, "%s%c", tmp, a[digits[3] - '0'][l]);
//                                     printf("4:%s\n", tmp);
//                                     ret[index ++] = tmp;
//                                     tmp = (char *) malloc(sizeof(char) * (n + 1));
//                                     memset(tmp, 0, n + 1);
//                                     if (l != n3 - 1) {
//                                         sprintf(tmp, "%c%c%c", a[digits[0] - '0'][i], a[digits[1] - '0'][j], a[digits[2] - '0'][k]);
//                                     }
//                                 }
//                             } else {
//                                 ret[index ++] = tmp;
//                                 tmp = (char *) malloc(sizeof(char) * (n + 1));
//                                 memset(tmp, 0, n + 1);
//                                 if (k != n2 - 1) {
//                                     sprintf(tmp, "%c%c", a[digits[0] - '0'][i], a[digits[1] - '0'][j]);
//                                 }
//                             }
//                         }
//                     } else {
//                         ret[index ++] = tmp;
//                         tmp = (char *) malloc(sizeof(char) * (n + 1));
//                         memset(tmp, 0, n + 1);
//                         sprintf(tmp, "%c", a[digits[0] - '0'][i]);
//                     }
//                 }
//             } else {
//                 ret[index ++] = tmp;
//                 tmp = (char *) malloc(sizeof(char) * (n + 1));
//                 memset(tmp, 0, n + 1);
//             }
//         }
//     }
//     if (tmp) {
//         free(tmp);
//     }

//     return ret;
// }

// 官方解答
char * phoneMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char * digits_tmp;
int digits_size;

char ** combinations;
int combinations_size;

char * combination;
int combination_size;

void backtrack(int index) {
    if (index == digits_size) {
        char * tmp = malloc(sizeof(char) * (combination_size + 1));
        memcpy(tmp, combination, sizeof(char) * (combination_size + 1));
        combinations[combinations_size ++] = tmp;
    } else {
        char digit = digits_tmp[index];
        char * letters = phoneMap[digit - '0'];
        int len = strlen(letters);
        for (int i = 0; i < len; i ++) {
            combination[combination_size ++] = letters[i];
            combination[combination_size] = 0;
            backtrack(index + 1);
            combination[-- combination_size] = 0;
        }
    }
}

char ** letterCombinations(char * digits, int * returnSize) {
    combinations_size = combination_size = 0;
    digits_tmp = digits;
    digits_size = strlen(digits);
    if (digits_size == 0) {
        * returnSize = 0;
        return combinations;
    }
    int num = 1;
    for (int i = 0; i < digits_size; i ++) {
        num *= 4;
    }
    combinations = (char **) malloc (sizeof(char *) * num);
    combination = (char *) malloc (sizeof(char) * digits_size);
    backtrack(0);
    * returnSize = combinations_size;
    return combinations;
}


int main (int argc, char ** argv) {
    int returnSize;
    char ** res = letterCombinations("234", & returnSize);
    printf("%d\n", returnSize);
    for (int i = 0; i < returnSize; i ++) {
        printf("#i: %d, string: %s\n", i, res[i]);
    }
    return 0;
}
