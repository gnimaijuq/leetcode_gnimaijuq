#include<stdlib.h>

int comp(const void * a, const void * b) {
    return * (int *) a >= * (int *) b;
}

int distributeCandies(int* candyType, int candyTypeSize){
    qsort(candyType, candyTypeSize, sizeof(int), comp);
    int cur_type = 1000000;
    int sum_type = 0;

    for (int i = 0; i < candyTypeSize; i ++) {
        if (candyType[i] != cur_type) {
            cur_type = candyType[i];
            if (sum_type < candyTypeSize / 2) {
                sum_type ++;
            } else {
                return sum_type;
            }
        }
    }
    return sum_type;
}
