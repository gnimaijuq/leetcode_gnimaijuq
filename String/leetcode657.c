#include<stdio.h>
#include<string.h>

int judgeCircle(char * moves){
    int postion[2] = {0, 0};
    for (int i = 0; i < strlen(moves); i ++) {
        if (moves[i] == 'U') {
            postion[0] ++;
        } else if (moves[i] == 'D') {
            postion[0] --;
        } else if (moves[i] == 'L') {
            postion[1] --;
        } else if (moves[i] == 'R') {
            postion[1] ++;
        }
    }

    // printf("%d %d\n", postion[0], postion[1]);
    if (postion[0] == 0 && postion[1] == 0) {
        return 1;
    }

    return 0;
}

int main(int argc, char * * argv) {
    // printf("%d\n", judgeCircle("RLUURDDDLU"));
    return 0;
}
