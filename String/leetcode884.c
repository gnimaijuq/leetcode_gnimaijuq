typedef struct {
    char * word;
    int val;
    UT_hash_handle hh;
} HashEntry;

bool insert(char * str, HashEntry ** obj) {
    HashEntry * pEntry = NULL;
    char * token = NULL;

    token = strtok(str, " ");
    while (token != NULL) {
        pEntry = NULL;
        HASH_FIND_STR(* obj, token, pEntry);
        if (NULL == pEntry) {
            HashEntry * pEntry = (HashEntry *) malloc (sizeof(HashEntry));
            pEntry->word = (char *) malloc (sizeof(char) * (strlen(token) + 1));
            strcpy(pEntry->word, token);
            pEntry->val = 1;
            HASH_ADD_STR(* obj, word, pEntry);
        } else {
            pEntry->val ++;
        }
        token = strtok(NULL, " ");
    }
    return true;
}

char * * uncommonFromSentences(char * s1, char * s2, int * returnSize) {
    HashEntry * freq = NULL;
    HashEntry * pEntry = NULL;

    insert(s1, & freq);
    insert(s2, & freq);
    unsigned int sentenceSize = HASH_COUNT(freq);
    char * * ans = (char * *) malloc (sizeof(char *) * sentenceSize);
    int pos = 0;
    HashEntry * curr = NULL, * next = NULL;
    HASH_ITER(hh, freq, curr, next) {
        if (curr->val == 1) {
            ans[pos] = (char *) malloc (sizeof(char) * (strlen(curr->word) + 1));
            strcpy(ans[pos], curr->word);
            pos ++;
        }
    }

    HASH_ITER(hh, freq, curr, next) {
        free(curr->word);
        HASH_DEL(freq, curr);
    }

    * returnSize = pos;
    return ans;
}
