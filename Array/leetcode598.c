int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    int min_x = m;
    int min_y = n;
    for (int i = 0; i < opsSize; i ++) {
        min_x = min_x > ops[i][0] ? ops[i][0] : min_x;
        min_y = min_y > ops[i][1] ? ops[i][1] : min_y;
    }

    return min_x * min_y;
}
