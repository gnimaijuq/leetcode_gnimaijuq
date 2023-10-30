#include<string.h>
#include<stdlib.h>

typedef struct {
    char * key;
    UT_hash_handle hh;
} HashSetItem;

typedef struct {
    char * key;
    int val;
    UT_hash_handle hh;
} HashMapItem;

#define MAX_STR_LEN 1024
#define MAX(a, b) ((a) > (b) ? (a) : (b))

char * mostCommonWord (char * paragraph, char * * banned, int bannedSize) {
    HashSetItem * bannedSet = NULL;
    for (int i = 0; i < bannedSize; i ++) {
        HashSetItem * pSetEntry = NULL;
        HASH_FIND_STR (bannedSet, banned[i], pSetEntry);
        if (NULL == pSetEntry) {
            pSetEntry = (HashSetItem *) malloc (sizeof(HashSetItem));
            pSetEntry->key = banned[i];
            HASH_ADD_STR(bannedSet, key, pSetEntry);
        }
    }

    int maxFrequency = 0;
    char * mostCommon = (char *) malloc (sizeof(char) * MAX_STR_LEN);
    HashMapItem * frequencies = NULL;
    char word[MAX_STR_LEN];
    int pos = 0;
    int length = strlen(paragraph);
    for (int i = 0; i <= length; i ++) {
        if (i < length && isalpha(paragraph[i])) {
            word[pos ++] = tolower(paragraph[i]);
        } else if (pos > 0) {
            HashSetItem * pSetEntry = NULL;
            word[pos] = 0;
            HASH_FIND_STR(bannedSet, word, pSetEntry);
            if (NULL == pSetEntry) {
                HashMapItem * pMapEntry = NULL;
                HASH_FIND_STR(frequencies, word, pMapEntry);
                if (NULL == pMapEntry) {
                    pMapEntry = (HashMapItem *) malloc (sizeof(HashMapItem));
                    pMapEntry->key = (char *) malloc (sizeof(char) * pos);
                    strcpy(pMapEntry->key, word);
                    pMapEntry->val = 1;
                    HASH_ADD_STR(frequencies, key, pMapEntry);
                } else {
                    pMapEntry->val ++;
                }

                if (maxFrequency < pMapEntry->val) {
                    maxFrequency = pMapEntry->val;
                    strcpy(mostCommon, word);
                }
            }
            pos = 0;
        }
    }
    return mostCommon;
}
