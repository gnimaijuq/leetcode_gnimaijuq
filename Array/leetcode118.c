/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    * returnSize = numRows;
    * returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    memset(* returnColumnSizes, 0, sizeof(int) * numRows);
    int ** retArr = (int **)malloc(sizeof(int *) * numRows);
    memset(retArr, 0, sizeof(int *) * numRows);
    for (int i = 0; i <= numRows - 1; i ++) {
        (* returnColumnSizes)[i] = i + 1;
        retArr[i] = (int *)malloc(sizeof(int) * (i + 1));
        memset(retArr[i], 0, sizeof(int) * (i + 1));
        retArr[i][0] = 1;
        retArr[i][i] = 1;
        for (int j = 1; j < i; j ++) {
            retArr[i][j] = retArr[i - 1][j - 1] + retArr[i - 1][j];
        }
    }

    return retArr;
}
