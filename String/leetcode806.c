/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int n = strlen(s);
    int sum = 0;
    * returnSize = 2;
    int col = 1;
    int * ret = (int *) malloc (sizeof(int) * 2);
    memset(ret, 0, sizeof(int) * 2);

    for (int i = 0; i < n; i ++) {
        if (sum + widths[s[i] - 'a'] > 100) {
            col ++;
            sum = widths[s[i] - 'a'];
        } else {
            sum += widths[s[i] - 'a'];
        }
    }

    ret[0] = col;
    ret[1] = sum;
    return ret;
}
