char * convertToTitle(int columnNumber){
    char * ret = (char *) calloc (8, sizeof(char));
    int index;
    for (int i = 6; i >= 0; i --) {
        ret[i] = 'A' + (columnNumber - 1) % 26;
        columnNumber = (columnNumber - 1) / 26;
        if (columnNumber == 0) {
            index = i;
            break;
        }
    }

    for (int i = 0; i < 8 && index < 8; i ++) {
        ret[i] = ret[index ++];
    }

    return ret;
}
