/*
 * 写出一个程序，接受一个有字母和数字以及空格组成的字符串， * 和一个字符，
 * 然后输出输入字符串中含有该字符的个数。不区分大小写。
 */

#include<iostream>
#include<string>
using namespace std;

int count(const string& s,const char ch) {
    int len;
    if ( (len = s.length()) <= 0 || ch == ' ')
        return 0;

    int cnt = 0;

    for (int i = 0; i < len; i++){
        if(ch == s[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main(){
    string s;
    char ch;

    while (cin >> s >> ch) {

        //int numbers_1 = count(s.begin(), s.end(), ch);
        int numbers_1 = count(s, ch);

        ch = (ch >= 'a' ? ch - 32 : ch + 32) ;
        //int numbers_2 = count(s.begin(), s.end(), ch);
        int numbers_2 = count(s, ch);

        cout << numbers_1 + numbers_2 << endl;
    }
    return 0;
}

// 使用std:count函数
#if 0

int main(){

    string s;
    char ch;

    while (cin >> s >> ch) {

        int numbers_1 = count(s.begin(), s.end(), ch);

        ch = (ch >= 'a' ? ch - 32 : ch + 32) ;
        int numbers_2 = count(s.begin(), s.end(), ch);

        cout << numbers_1 + numbers_2 << endl;
    }
    return 0;
}

#endif
