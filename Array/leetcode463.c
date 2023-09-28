int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int ret = 0;
    int count = 0;

    for (int i = 0; i < gridSize; i ++) {
        for (int j = 0; j < * gridColSize; j ++) {
            if (grid[i][j] == 1) {
                if (count == 0) {
                    ret = 4;
                    count ++;
                } else {
                    if (i != 0 && j != 0) {
                        ret += 1 & grid[i - 1][j] & grid[i][j - 1] & grid[i - 1][j - 1] ? 0 : 2;
                    } else {
                        ret += 2;
                    }
                }
            }
        }
    }

    return ret;
}
