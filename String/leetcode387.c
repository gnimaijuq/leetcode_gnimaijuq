// int firstUniqChar(char * s){
//     for (int i = 0; i < strlen(s); i ++) {
//         if (s[i] != '0') {
//             int flag = 0;
//             for (int j = i + 1; j < strlen(s); j ++) {
//                 if (s[j] == s[i]) {
//                     s[j] = '0';
//                     flag = 1;
//                 }
//             }
//             if (!flag) {
//                 return i;
//             }
//         }
//     }

//     return -1;
// }

// 哈希解答
#include<stdio.h>
#include<uthash.h>

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

int firstUniqChar (char * s) {
    struct hashTable * frequency = NULL;
    int n = strlen(s);
    for (int i = 0; i < n; i ++) {
        int ikey = s[i];
        struct hashTable * tmp;
        HASH_FIND_INT(frequency, & ikey, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = ikey;
            tmp->val = 1;
            HASH_ADD_INT(frequency, key, tmp);
        } else {
            tmp->val ++;
        }
    }

    for (int i = 0; i < n; i ++) {
        int ikey = s[i];
        struct hashTable * tmp;
        HASH_FIND_INT(frequency, & ikey, tmp);
        if (tmp != NULL && tmp->val == 1) {
            return i;
        }
    }

    return -1;
}
