/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<string.h>

char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    int malloc_size = list1Size > list2Size ? list2Size : list1Size;
    char ** retT = (char **)malloc(sizeof(char *) * malloc_size);
    int index = malloc_size - 1;
    * returnSize = 0;
    int min_index_sum = list1Size + list2Size - 2;
    for (int i = 0; i < list1Size; i ++) {
        if (i != 0 && i > min_index_sum) {
            break;
        }
        for (int j = 0; j < list2Size; j ++) {
            if (!strcmp(list1[i], list2[j]) && i + j <= min_index_sum) {
                * returnSize = i + j < min_index_sum ? 1 : * returnSize + 1;
                min_index_sum = i + j;
                char * temp = (char *) malloc (sizeof(char) * 30);
                sprintf(temp, "%s", list1[i]);
                retT[index --] = temp;
                break;
            }

            if (i + j > min_index_sum) {
                break;
            }
        }
    }

    for (int i = 0; i < * returnSize && index < malloc_size; i ++) {
        retT[i] = retT[++ index];
    }
    for (int i = index + 1; i < malloc_size; i ++) {
        free(retT[i]);
    }

    return retT;
}
