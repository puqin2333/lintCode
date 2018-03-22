//
//  main.cpp
//  最长回文数
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
    // 最长回文子串
    string longestPalindrome(string s) {
        if (s.empty() == 0) {
            return "";
        }
        if (s.length() == 1) {
            return  s;
        }
        vector<string> sub1 = subString(s);
        s.reserve();
        vector<string> sub2 = subString(s);
        for (int i = 0; i < sub2.size(); i++) {
            for (int j = 0; j < sub2.size(); j++) {
                if ( ) {
                    <#statements#>
                }
            }
        }
    }
private:
    vector<string> subString(string s) {
        vector<string> subStr;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; j < s.length(); j++) {
                subStr[i] = s.substr(i,s.length() - j);
            }
        }
        return subStr;
    }
};
int main(int argc, const char * argv[]) {
    Solution solution;
    string s;
    cin >> s;
    cout << solution.longestPalindrome(s) << endl;
    
    return 0;
}
