//
//  main.cpp
//  连接两个字符串中的不同字符
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/11/6.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//


/*  题目描述：
     给出两个字符串, 你需要修改第一个字符串，将所有与第二个字符串中相同的字符删除,
     并且第二个字符串中不同的字符与第一个字符串的不同字符连接
 */
/* 样例：
 给出 s1 = aacdb, s2 = gafd
 返回 cbgf
 给出 s1 = abcs, s2 = cxzca;
 返回 bsxz
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /*
     * @param : the 1st string
     * @param : the 2nd string
     * @return: uncommon characters of given strings
     */
    string concatenetedString(string &s1, string &s2) {
        string str,str1,str2;
        int temp;
        for (int i = 0; i < s1.length(); i++) {
            temp = 0;
            for (int j = 0; j < s2.length(); j++) {
                if (s1[i] == s2[j]) {
                    temp = 1;
                }
            }
            char s = s1[i];
            if (temp == 0) {
                str1.append(&s);
            }
        }
        for (int i = 0; i < s2.length(); i++) {
            temp = 0;
            for (int j = 0; j < s1.length(); j++) {
                if (s2[i] == s1[j]) {
                    temp = 1;
                }
            }
            char s = s2[i];
            if (temp == 0) {
                str2.append(&s);
            }
        }
        str.append(str1);
        str.append(str2);
        return str;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    string s1,s2;
    cin >> s1 >> s2;
    cout << solution.concatenetedString(s1, s2) << endl;
    return 0;
}
