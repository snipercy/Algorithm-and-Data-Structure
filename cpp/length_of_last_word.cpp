/* 题目：计算字符串最后一个单词的长度，单词以空格隔开。
 * 出处：牛客网
 *
 * 时间复杂度 O(N)
 * 空间复杂度 O(1)
 *
 * 思路：逐字符读入输入字符，不断更新当前遍历的单词长度，
 * 读取完输入文件也就处理结束。
 */
#include<stdio.h>

int main() {
    char ch;
    int len = 0;
    int pre = 0;
    while((ch = getchar()) != '\n') {
        if (ch != ' ') {
            len++;
            // 保存当前单词的长度len，防止文本行末尾有空格，丢失len的值
            pre = len;
        } else {
            len = 0;
        }
    }

    len = (len == 0 ? pre : len);
    printf("%d\n", len);

    return 0;
}

