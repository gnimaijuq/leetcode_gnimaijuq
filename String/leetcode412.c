/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<string.h>

char ** fizzBuzz(int n, int* returnSize){
    char * * answer = (char * *) malloc (sizeof(char *) * n);
    * returnSize = n;
    for (int i = 1; i <= n; i ++) {
        char * tmp;
        if (i % 15 == 0) {
            tmp = (char *) malloc (sizeof(char) * 9);
            sprintf(tmp, "%s", "FizzBuzz");
        } else if (i % 3 == 0) {
            tmp = (char *) malloc (sizeof(char) * 5);
            sprintf(tmp, "%s", "Fizz");
        } else if (i % 5 == 0) {
            tmp = (char *) malloc (sizeof(char) * 5);
            sprintf(tmp, "%s", "Buzz");
        } else {
            tmp = (char *) malloc (sizeof(char) * 5);
            sprintf(tmp, "%d", i);
        }
        answer[i - 1] = tmp;
    }
    return answer;
}
