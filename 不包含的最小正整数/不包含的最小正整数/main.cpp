//
//  main.cpp
//  不包含的最小正整数
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/22.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//


/*
 题目描述： 在十进制表示中，任意一个正整数都可以用字符‘0’-‘9’表示出来。但是当‘0’-‘9’这些字符每种字符的数量有限时，可能有些正整数就无法表示出来了。比如你有两个‘1’ ，一个‘2’ ，那么你能表示出 11，12，121 等等，但是无法表示出 10，122，200 等数。现在你手上拥有一些字符，它们都是‘0’-‘9’的字符。你可以选出其中一些字符然后将它们组合成一个数字，那么你所无法组成的最小的正整数是多少？
 */
/*
 输入
 第一行包含一个由字符’0’-‘9’组成的字符串，表示你可以使用的字符。
 
 · 1 ≤字符串长度≤ 1000
 
 输出
 输出你所无法组成的最小正整数。
 
 
 样例输入
 55 112334556778990 1234567890 1122334455667788990
 
 样例输出
 1 22 11100
 */

// 解法分析： 特殊问题分布判断
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void noMinNumberOfString(string s) {
        vector<int> hashTable(10,0);
        vector<int> noNumber;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] < '0' || s[i] > '9') {
                return;
            }
            hashTable[s[i] - '0'] ++;
        }
        for (int i = 0; i < 10; i++) {
            if (hashTable[i] == 0) {
                noNumber.push_back(i);
            }
        }
        bool flag_isOnlyZero = false;
        for (int i = 0; i < noNumber.size(); i++) {
            if (noNumber[i]) {
                cout << noNumber[i];
                break;
            } else {
                if (noNumber.size() == 1 && noNumber[i] == 0) {
                    flag_isOnlyZero = true;
                }
            }
        }
        if (flag_isOnlyZero) {
            cout << 10;
        }
        bool flag_isAllSameTime = false;
        int minLetterTime = hashTable[0], minLetter = 9;
        if (noNumber.size() == 0) {
            for (int i = 0; i < 10; i++) {
                if(minLetterTime >= hashTable[i]) {
                    minLetterTime = hashTable[i];
                    if (minLetter > i) {
                        minLetter = i;
                    }
                    flag_isAllSameTime = true;
                }
            }
            if (!flag_isAllSameTime) {
                for (int i = 0; i <= minLetterTime; i++) {
                    cout << 1;
                }
            } else {
                if (minLetter == 0) {
                    cout << 1;
                }
                for (int i = 0; i <= minLetterTime; i++) {
                    cout << minLetter;
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    Solution solution;
    solution.noMinNumberOfString(s);
    
    return 0;
}
