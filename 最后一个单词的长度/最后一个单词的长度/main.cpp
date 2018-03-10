//
//  main.cpp
//  最后一个单词的长度
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/10.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

/// length of Last Word
/// 题目描述：Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
/// If the last word does not exist, return 0.
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0  ,tail = 0;
        tail = (int)s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') {
            tail--;
        }
        while (tail >= 0 && s[tail] != ' ') {
            length++;
            tail--;
        }
        return length;
    }
};

int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    Solution solution;
    cout << solution.lengthOfLastWord(s) << endl;
    return 0;
}
