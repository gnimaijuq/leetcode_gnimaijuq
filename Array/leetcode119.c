/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int ** retT_p = (int **)malloc(sizeof(int*) * (rowIndex + 1));
    memset(retT_p, 0, sizeof(int*) * (rowIndex + 1));
    * returnSize = rowIndex + 1;
    for (int i = 0; i <= rowIndex; i ++) {
        retT_p[i] = (int *)malloc(sizeof(int *) * (i + 1));
        memset(retT_p[i], 0, sizeof(int *) * (i + 1));
        retT_p[i][0] = retT_p[i][i] = 1;
        for(int j = 1; j < i; j ++) {
            retT_p[i][j] = retT_p[i - 1][j - 1] + retT_p[i - 1][j];
        }
    }

    return retT_p[rowIndex];
}
