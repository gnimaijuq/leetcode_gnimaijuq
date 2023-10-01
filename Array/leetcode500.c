/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<string.h>

char ** findWords(char ** words, int wordsSize, int* returnSize){
    char ** retT = (char **)malloc(sizeof(char *) * wordsSize);
    * returnSize = 0;
    int index = 0;
    // char first_line[10] = {'q','w','e','r','t','y','u','i','o','p'};
    // char second_line[9] = {'a','s','d','f','g','h','j','k','l'};
    // char third_line[7] = {'z','x','c','v','b','n','m'};
    char * first_line = "qwertyuiop";
    char * second_line = "asdfghjkl";
    char * third_line = "zxcvbnm";
    for (int i = 0; i < wordsSize; i ++) {
        char * line_2_find = NULL;
        int check_flag = 0;
        for (int j = 0; j < strlen(words[i]); j ++) {
            char check_word = words[i][j];
            if (words[i][j] < 'a') {
                check_word = words[i][j] + 'a' - 'A';
            }

            if (line_2_find) {
                int res = strchr(line_2_find, check_word);
                if (res) {
                    check_flag = 1;
                    continue;
                } else {
                    check_flag = 0;
                    break;
                }
            }

            if(strchr(first_line, check_word)) {
                line_2_find = first_line;
            } else if (strchr(second_line, check_word)) {
                line_2_find = second_line;
            } else if (strchr(third_line, check_word)) {
                line_2_find = third_line;
            }

            if (line_2_find) {
                check_flag = 1;
            }
        }
        if (check_flag) {
            * returnSize += 1;
            retT[index ++] = words[i];
        }
    }
    return retT;
}
