// #include<string.h>

// int countSegments(char * s){
//     int ret = 0;
//     ret += strtok(s, " ") ? 1 : 0;
//     while (s = strtok(NULL, " ")) {
//         ret += s ? 1 : 0;
//     }

//     return ret;
// }

int countSegments(char * s) {
    int ret = 0;
    int n = strlen(s) - 1;
    int flag = 0;
    while (n >= 0) {
        if (s[n --] == ' ') {
            ret += flag == 1 ? 1 : 0;
            flag = 0;
        } else {
            flag = 1;
        }
    }
    if (flag) {
        ret += 1;
    }

    return ret;
}
