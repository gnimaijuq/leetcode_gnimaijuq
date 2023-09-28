#include<stdlib.h>
int comp (const void * a, const void * b) {
    return * (int *) a >= * (int *) b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize){
    int count = 0;
    qsort(g, gSize, sizeof(int), comp);
    qsort(s, sSize, sizeof(int), comp);

    for (int g_index = 0, s_index = 0; g_index < gSize && s_index < sSize;) {
        if (g[g_index] <= s[s_index]) {
            count ++;
            s_index ++;
            g_index ++;
        } else {
            s_index ++;
        }
    }

    return count;
}
