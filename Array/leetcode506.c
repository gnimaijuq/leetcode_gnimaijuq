/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>

int comp(const void * a, const void * b) {
    return * (int *) a <= * (int *) b;
}

char ** findRelativeRanks(int* score, int scoreSize, int* returnSize){
    int * tmp = (int *)malloc(sizeof(int) * scoreSize);
    char ** retT = (char **)malloc(sizeof(char *) * scoreSize);
    * returnSize = scoreSize;
    for (int i = 0; i < scoreSize; i ++) {
        tmp[i] = score[i];
    }

    qsort(tmp, scoreSize, sizeof(int), comp);

    char * temp = (char *) malloc (sizeof(char) * 16);
    for (int i = 0; i < scoreSize; i ++) {
        char * temp = (char *) malloc (sizeof(char) * 16);
        for (int j = 0; j < scoreSize; j ++) {
            if (score[i] == tmp[j]) {
                if (j == 0) {
                    retT[i] = "Gold Medal";
                } else if (j == 1) {
                    retT[i] = "Silver Medal";
                } else if (j == 2) {
                    retT[i] = "Bronze Medal";
                } else {
                    sprintf(temp, "%d", j + 1);
                    retT[i] = temp;
                }

                break;
            }
        }
    }

    return retT;
}
