#include<string.h>
#include<stdio.h>
#include<malloc.h>

char * convert(char * s, int numRows){
    int len = strlen(s);
    if (len == 0 || numRows == 1) {
        return s;
    }

    char * a = (char *) malloc (sizeof(char) * (len + 1));
    a[len] = '\0';
    // 第一行的元素都能整除这个值
    // 其余的数相除后靠的距离相同的在同一行。
    int k = 2 * numRows - 2;

    int n = 0;
    for (int i = 0; i < numRows; i ++) {
        for (int j = 0; j < len; j ++) {
            if (j % k == i || j % k == k - i) {
                a[n ++] = s[j];
            }
        }
    }
    return a;
}

// char * convert(char * s, int numRows)
// {
//     int n = strlen(s);
//     if (n == 0 || numRows == 1) {
//         return s;
//     }
//     char ** a = (char **) malloc (sizeof(char *) * numRows);
//     char * ret = (char *) malloc (sizeof(char) * (n + 1));
//     memset(ret, '\0', n + 1);
//     for(int i = 0; i < numRows; i ++) {
//         a[i] = (char *) malloc (sizeof(char) * (n + 1));
//         memset(a[i], '\0', n + 1);
//     }


//     int flag = - 1;
//     int index = 0;
//     for (int i = 0; index < n; i += flag){
//         printf("i = %d\n",i);
//         if (i == 0 || i == (numRows - 1)) {
//             flag = - flag;
//         }

//         // printf("sizeof(a[i]) = %ld\n",sizeof(a[i]));
//         // printf("strlen(a[i]) = %ld\n",strlen(a[i]));
//         // printf("#i = %d, index = %d\n",i,index);
//         sprintf(a[i], "%s%c",a[i], s[index ++]);
//         // printf("a[i]:%s\n", a[i]);
//     }

//     for (int i = 0; i < numRows; i++){
//         sprintf(ret, "%s%s", ret, a[i]);
//         free(a[i]);
//     }
//     free(a);
//     return ret;
// }

int main(int argc, char ** argv) {
    char * res = convert("AB", 1);
    printf("%s\n", res);
    return 0;
}
