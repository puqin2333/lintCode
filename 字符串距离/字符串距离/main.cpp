//
//  main.cpp
//  字符串距离
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/23.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

/// 题目描述：给出两个相同长度的由字符 a 和 b 构成的字符串，定义它们的距离为对应位置不同的字符的数量。如串“aab”与“aba”的距离为2;串“ba”与串“aa”的距离为1; 串“baa”和串“baa”的距离为0，下面给出两个字符串S和T，其中S的长度不小于T的长度。我们用|S|代表S的长度，|T|代表T的长度，那么在S中一共有|S|。|T|+1个与T长度相同的子串，现在你需要计算T串与这些|S|-|T+1|个子串的距离的和。

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int distanceSum(string s, string t) {
        int sum = 0;
        for (int i = (int)t.length(); i <= s.length(); i++) {
            sum += distanceSumOfTwoString(t, s.substr(i - t.length(), i));
        }
        return sum;
    }
private:
    int distanceSumOfTwoString(string s, string t) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                sum ++;
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    string s, t;
    cin >> s;
    cin >> t;
    Solution solution;
    cout << solution.distanceSum(s, t) << endl;
    return 0;
}
