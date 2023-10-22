// char * intToRoman(int num){
//     char * s = (char *) malloc (sizeof(char) * 20);
//     memset(s, 0, 20);
//     int index = 0;
//     // 商：a，余数：b
//     int a, b;

//     // M
//     a = num / 1000;
//     b = num % 1000;
//     for (int i = 0; i < a; i ++) {
//         s[index ++] = 'M';
//     }
//     if (b >= 900) {
//         b = b - 900;
//         s[index ++] = 'C';
//         s[index ++] = 'M';
//     }

//     // D
//     a = b / 500;
//     b %= 500;
//     for (int i = 0; i < a; i ++) {
//         s[index ++] = 'D';
//     }
//     if (b >= 400) {
//         b = b - 400;
//         s[index ++] = 'C';
//         s[index ++] = 'D';
//     }

//     // C
//     a = b / 100;
//     b %= 100;
//     for (int i = 0; i < a; i ++) {
//         s[index ++] = 'C';
//     }
//     if (b >= 90) {
//         b = b - 90;
//         s[index ++] = 'X';
//         s[index ++] = 'C';
//     }

//     // L
//     a = b / 50;
//     b %= 50;
//     for (int i = 0; i < a; i ++) {
//         s[index ++] = 'L';
//     }
//     if (b >= 40) {
//         b = b - 40;
//         s[index ++] = 'X';
//         s[index ++] = 'L';
//     }

//     // X
//     a = b / 10;
//     b %= 10;
//     for (int i = 0; i < a; i ++) {
//         s[index ++] = 'X';
//     }
//     if (b >= 9) {
//         b = b - 9;
//         s[index ++] = 'I';
//         s[index ++] = 'X';
//     }

//     // V
//     a = b / 5;
//     b %= 5;
//     for (int i = 0; i < a; i ++) {
//         s[index ++] = 'V';
//     }
//     if (b >= 4) {
//         b = b - 4;
//         s[index ++] = 'I';
//         s[index ++] = 'V';
//     }

//     for (int i = 0; i < b; i ++) {
//         s[index ++] = 'I';
//     }
//     s[index] = '\0';

//     return s;
// }

// 官方解答
const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

char* intToRoman(int num) {
    char* roman = malloc(sizeof(char) * 16);
    roman[0] = '\0';
    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            strcpy(roman + strlen(roman), symbols[i]);
        }
        if (num == 0) {
            break;
        }
    }
    return roman;
}
