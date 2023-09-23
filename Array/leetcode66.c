/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int isAllNine = 0;
    for (int i = 0; i < digitsSize; i ++) {
        if (digits[i] != 9) {
            break;
        }

        if (i == digitsSize - 1) {
            isAllNine = 1;
        }
    }
    int * retTable;
    if (isAllNine) {
        * returnSize = digitsSize + 1;
        retTable = (int *)malloc(sizeof(int) * (digitsSize + 1));
        if (! retTable) {
            return 0;
        }
    } else {
        * returnSize = digitsSize;
        retTable = (int *)malloc(sizeof(int) * digitsSize);
        if (! retTable) {
            return 0;
        }
    }

    int index = * returnSize - 1;

    int over_flag = 0;
    int tmp = digits[digitsSize - 1] + 1;
    if (tmp >= 10) {
        retTable[index] = 0;
        over_flag = 1;
    } else {
        retTable[index] = tmp;
    }
    index --;

    for (int i = digitsSize - 2; i >= 0; i --)
    {
        if (!over_flag) {
            retTable[index] = digits[i];
        } else {
            if (digits[i] + 1 >= 10) {
                retTable[index] = 0;
            } else {
                retTable[index] = digits[i] + 1;
                over_flag = 0;
            }
        }
        index --;
    }

    if (over_flag) {
        retTable[0] = 1;
    }

    return retTable;
}
