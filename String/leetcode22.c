/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<math.h>
#include<string.h>
#include<memory.h>
#include<stdio.h>
#include<malloc.h>

#define MAX_SIZE 1430

char * a = "()";
int len;
int left = 0, right = 0;

char * combination;
int combination_size;

char ** combinations;
int combinations_size;

void backtrack(int index, int left, int right) {
    if (index == len * 2) {
        char * tmp = (char *) malloc (sizeof(char) * (combination_size + 1));
        memcpy(tmp, combination, sizeof(char) * combination_size + 1);
        combinations[combinations_size ++] = tmp;
        return;
    }

    if (left < len) {
        combination[combination_size ++] = '(';
        combination[combination_size] = 0;
        backtrack(index + 1, left + 1, right);
        combination[-- combination_size] = 0;
    }
    if (left > right && right < len) {
        combination[combination_size ++] = ')';
        combination[combination_size] = 0;
        backtrack(index + 1, left, right + 1);
        combination[-- combination_size] = 0;
    }
}

char ** generateParenthesis(int n, int* returnSize){
    len = n;
    combinations_size = combination_size = 0;
    if (n == 0) {
        * returnSize = 0;
        return combinations;
    }
    combinations = (char **) malloc(sizeof(char *) * MAX_SIZE);
    combination = (char *) malloc(sizeof(char) * (2 * n + 1));
    backtrack(0, left, right);
    * returnSize = combinations_size;
    return combinations;
}
