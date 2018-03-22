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
        // start 的作用是记录第一个不重复的字符的下标，如果出现重复字符，则 start 进行改变
        int start = -1, maxLength = 0;
        // 创建一个哈希表，来存储字符串，key 为 字符， value 为字符出现的下标
        vector<int> table(256, -1);
        for (int i = 0;  i < s.length(); i++) {
            // 默认start 为-1，
            if (table[s[i]] > start) {
                start = table[s[i]];
            }
            table[s[i]] = i;
            maxLength = max(maxLength, i - start);
        }
        return maxLength;
    }
};

class Solution1 {
public:
    int minNumberofString(string s) {
        int minNumber = 0;
        vector<int> hashTable(10,0);
        vector<int> noNumber;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] < '0' || s[i] > '9') {
                return 0;
            }
            hashTable[s[i] - '0'] ++;
        }
        for (int i = 0; i < hashTable.size(); i++) {
            if (hashTable[i] == 0) {
                noNumber.push_back(hashTable[i]);
            }
        }
        int min = 0;
        for (int i = 0; i < noNumber.size(); i++) {
            if (noNumber[i] != 0 ) {
                return noNumber[i];
            } else {
                return min * 10 + 0;
            }
        }
        return 0;
    };
    int distanceSum(string s, string t) {
        int sum = 0;
        for (int i = t.length(); i <= s.length(); i++) {
            sum += distanceSumOfTwoString(t, s.substr(i - t.length(), i));
        }
        return sum;
    };
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
    Solution1 solution1;
    cout << solution1.distanceSum(s, t) << endl;

    vector<int> num(10,0);
    for (int i = 0; i < s.length(); i++) {
        num[s[i] - 48] ++;
    }
    int min=1,min1 =1;
    int minNum = num[1], minNum1 = num[1];
    for (int i=0;i<10;i++) {
        if (num[i]<minNum) {
            min = i;
            minNum = num[i];
        } else if (min ==0 && i!=0 && num[i] == minNum){
                min = i;
                minNum = num[i];
        }
        if (i != 0) {
            if (num[i] <minNum1) {
                minNum1 = num[i];
                min1 = i;
            }
        }
    }
    if (min == 0 && minNum1!=0){
        cout << 1;
    }
    if (minNum1 != 0) {
        for (int i = 0; i <= minNum; i++) {
            cout << min;
        }
    } else {
        cout << min1;
    }
    return 0;
}

