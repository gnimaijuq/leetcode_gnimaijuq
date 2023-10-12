bool canConstruct(char * ransomNote, char * magazine){
    for (int i = 0; i < strlen(ransomNote); i ++) {
        for (int j = 0; j < strlen(magazine); j ++) {
            if (ransomNote[i] == magazine[j]) {
                magazine[j] = '0';
                break;
            }

            if (j == strlen(magazine) - 1) {
                return false;
            }
        }
    }

    return true;
}
