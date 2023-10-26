/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// 他人题解
#include<stdio.h>
#include<stdlib.h>

struct hashTable {
    char* key;
    int index;
    int cnt;
    UT_hash_handle hh;
};

int cmp (const void* a, const void* b) {
    return *(char*)a > *(char*)b;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    if (strsSize == 0) return NULL;
    char ***res = (char ***)malloc(sizeof(char **) * strsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);
    *returnSize = 0;
    struct hashTable *set = NULL;
    for(int i=0; i<strsSize; i++){
        int len = strlen(strs[i]);
        char strtmp[len+1];
        memset(strtmp, 0, sizeof(char) * (len+1));
        memcpy(strtmp, strs[i], sizeof(char) * len);
        // qsort tmp
        qsort(strtmp, len, sizeof(char), cmp);
        struct hashTable *tmp;
        HASH_FIND_STR(set, strtmp, tmp);
        if(tmp == NULL) {
            // HASH表中没有
            tmp= (struct hashTable *)malloc(sizeof(struct hashTable));
            tmp->key = (char*)calloc(len + 1, sizeof(char));
            memset(tmp->key, 0, sizeof(char) * (len + 1));
            memcpy(tmp->key, strtmp, sizeof(char) * len);
            tmp->index = *returnSize;
            tmp->cnt = 1;
            HASH_ADD_STR(set, key, tmp);
            res[*returnSize] = (char **)malloc(sizeof(char*) * strsSize);
            res[*returnSize][tmp->cnt-1] = (char *)malloc(sizeof(char) * (len + 1));
            memset(res[*returnSize][tmp->cnt-1], 0, sizeof(char) * (len + 1));
            memcpy(res[*returnSize][tmp->cnt-1], strs[i], sizeof(char) * len);
            (*returnColumnSizes)[*returnSize] = tmp->cnt;
            (*returnSize)++;
        }
        else {
            // HASH表中有记录
            res[tmp->index][tmp->cnt] = (char *)malloc(sizeof(char) * (len + 1));
            memset(res[tmp->index][tmp->cnt], 0, sizeof(char) * (len + 1));
            memcpy(res[tmp->index][tmp->cnt], strs[i], sizeof(char) * len);
            tmp->cnt += 1;
            (*returnColumnSizes)[tmp->index] = tmp->cnt;

        }
    }

    return res;
}
