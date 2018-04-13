//
//  main.cpp
//  最长回文子串
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/12.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    // 最长回文子串 动态规划
//    string longestPalindrome(string s) {
//        int len = s.length();
//        if (s.length() <= 1) {
//            return  s;
//        }
//        bool dp[len][len]; // dp[i][j]表示 s[i..j] 是否是回文
//        memset(dp, 0, sizeof(dp));
//        int resLeft = 0, resRight = 0;
//        dp[0][0] = true;
//        for (int i = 1; i < len; i++) {
//            dp[i][i] = true;
//            dp[i][i-1] = true;
//        }
//
//        for (int k = 2; k <= len; k++) { // 枚举子串长度
//            for (int i = 0; i <= len - k; i++) { // 枚举子串起始位置
//                if (s[i] == s[i + k - 1] && dp[i + 1][i + k - 2]) {
//                    dp[i][i + k - 1] = true;
//                    if (resRight - resLeft + 1 < k) {
//                        resLeft = i;
//                        resRight = i + k - 1;
//                    }
//                }
//            }
//        }
//        return s.substr(resLeft, resRight - resLeft + 1);
//    }
//
    string longestPalindrome(string s) {
        int len = s.length();
        if (len <= 1) {
            return s;
        }
        int start, maxLen = 0;
        for (int i = 0; i < len; i++) {
            // 寻找以 i-1,i为中心偶数长度的回文
            int low = i-1, high = i;
            while (low >= 0 && high < len && s[low] == s[high]) {
                low--;
                high++;
            }
            if (high - low - 1 > maxLen) {
                maxLen = high - low - 1;
                start = low + 1;
            }
            // 寻找以 i为中心偶数长度的回文
            low = i-1, high = i + 1;
            while (low >= 0 && high < len && s[low] == s[high]) {
                low--;
                high++;
            }
            if (high - low - 1 > maxLen) {
                maxLen = high - low - 1;
                start = low + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    string s;
    cin >> s;
    cout << solution.longestPalindrome(s) << endl;
    
    return 0;
}
