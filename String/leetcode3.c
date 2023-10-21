#include<stdio.h>
#include<string.h>

// 题解
int lengthOfLongestSubstring(char * s){
    int max_length = 0;
    int left = 0;
    int right = 0;
    int hash[127] = {0};
    while (s[right]) {
        // 当这个字符的hash值对应的位置不为0，并且left在这个值
        // 的左边，说明子串出现了重复。需要将left移动到这个字符
        // 重复字符的下一位。
        if (hash[s[right]] && left < hash[s[right]]) {
            left = hash[s[right]];
        }

        // 记录该字符的下一个位置
        hash[s[right]] = right + 1;
        max_length = max_length < (right - left + 1) ? (right - left + 1) : max_length;
        right ++;
    }
    return max_length;
}

int main(int argc, char ** argv) {
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    return 0;
}
