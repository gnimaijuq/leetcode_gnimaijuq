#include<malloc.h>
#include<stdio.h>
#include<string.h>

char * a[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int uniqueMorseRepresentations(char ** words, int wordsSize){
    char * * Strings = (char * *) malloc (sizeof(char *) * wordsSize);

    for (int i = 0; i < wordsSize; i ++) {
        Strings[i] = (char *) calloc(12 * 4, sizeof(char));
        for (int j = 0; j < strlen(words[i]); j ++) {
            sprintf(Strings[i], "%s%s", Strings[i], a[words[i][j] - 'a']);
        }
    }

    int count = 0;
    for (int i = 0; i < wordsSize; i ++) {
        if (* Strings[i] != '\0') {
            count ++;
            for (int j = i + 1; j < wordsSize; j ++) {
                if (!strcmp(Strings[i], Strings[j])) {
                    Strings[j][0] = '\0';
                }
            }
        }

        if (Strings[i]) {
            free(Strings[i]);
        }
    }

    if (Strings) {
        free(Strings);
    }

    return count;
}
