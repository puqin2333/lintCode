//
//  main.cpp
//  最长不重复字串
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/15.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

/// 算法描述：给定一个字符串，查找最长子字符串的长度，要求：该字串没有重复字符。
/// 输入实例：Given "abcabcbb", the answer is "abc", which the length is 3.
///           Given "bbbbb", the answer is "b", with the length of 1.
///           Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

/// 个人思路：算法复杂度为O（n * log(k)），新建一个字符数组，对字符串一次遍历，遍历的过程，与新建数组的元素进行比较，如果不同则添加；相同的话，将数组清空，存入当前的字符，length 长度为1.
/// 网上思路：时间复杂度为o(n)，空间复杂度为o(256)，建一个字典，key 为 字符串的字符， value 为 当前字符的位置


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1, maxLength = 0;
        vector<int> table(256, -1);
        for (int i = 0;  i < s.length(); i++) {
            if (table[s[i]] > start) {
                start = table[s[i]];
            }
            table[s[i]] = i;
            maxLength = max(maxLength, i - start);
        }
        return maxLength;
    }
};
int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
