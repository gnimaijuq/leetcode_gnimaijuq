/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes){
    * returnSize = imgSize;
    * returnColumnSizes = (int *) malloc (sizeof(int) * (* returnSize));
    int ** retT = (int **) malloc (sizeof(int *) * (* returnSize));
    for (int i = 0; i < * returnSize; i ++) {
        (* returnColumnSizes)[i] = * imgColSize;
        retT[i] = (int *) malloc (sizeof(int) * (* returnColumnSizes)[i]);
        memset(retT[i], 0, sizeof(int) * (* returnColumnSizes)[i]);
    }

    for (int i = 0; i < imgSize; i ++) {
        for (int j = 0; j < * imgColSize; j ++) {
            int sum = 0;
            int count = 9;
            count += i == 0 && j == 0 ? -5 : i == 0 || j == 0 ? -3 : 0;
            count += i == imgSize - 1 && j == (* imgColSize) - 1 ? -5 : \
                        i == imgSize - 1 || j == (* imgColSize) - 1 ? -3 : 0;

            count += j == 0 && i == imgSize - 1 ? 1 : 0;
            count += i == 0 && j == (* imgColSize) - 1 ? 1 : 0;
            int a = i - 1 < 0 ? i : i - 1;
            int b = i + 1 >= imgSize ? i : i + 1;
            int c = j - 1 < 0 ? j : j - 1;
            int d = j + 1 >= (* imgColSize) ? j : j + 1;
            sum = img[a][j] + img[i][c] + img[i][j] + img[i][d] + img[b][j];
            if (a != i) {
                sum += c != j ? img[a][c] : img[i][j];
                sum += d != j ? img[a][d] : img[i][j];
            } else {
                sum += img[i][j] * 2;
            }

            if (b != i) {
                sum += c != j ? img[b][c] : img[i][j];
                sum += d != j ? img[b][d] : img[i][j];
            } else {
                sum += img[i][j] * 2;
            }

            sum -= (9 - count) * img[i][j];

            retT[i][j] = sum / count;
        }
    }

    return retT;
}
