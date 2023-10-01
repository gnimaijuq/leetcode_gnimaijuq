/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    if (matSize * (* matColSize) != r * c) {
        * returnSize = matSize;
        * returnColumnSizes = (int *)malloc(sizeof(int) * matSize);
        for (int i = 0; i < matSize; i ++) {
            (* returnColumnSizes)[i] = * matColSize;
        }
        return mat;
    }

    * returnSize = r;
    * returnColumnSizes = (int *)malloc(sizeof(int) * r);

    int ** retT = (int **)malloc(sizeof(int *) * r);
    int ori_i = 0;
    int ori_j = 0;
    for (int i = 0; i < r; i ++) {
        (* returnColumnSizes)[i] = c;
        retT[i] = (int *)malloc(sizeof(int) * c);
        memset(retT[i], 0, sizeof(int) * c);

        for (int j = 0; j < c; j ++) {
            retT[i][j] = mat[ori_i][ori_j];
            ori_j ++;
            if (ori_j >= *matColSize) {
                ori_j = 0;
                ori_i ++;
                if (ori_i >= matSize) {
                    return retT;
                }
            }
        }
    }

    return retT;
}
