//
//  main.cpp
//  回文数
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/16.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    /*
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    bool isPalindrome(int num) {
        string s = to_string(num);
        int length = (int)s.length();
        for (int i = 0; i < length/2; i++) {
            if (s[i] != s[length - i - 1]) {
                return false;
            }
        }
        return true;
    }

};

int main(int argc, const char * argv[]) {
    Solution solution;
    int n;
    cin >> n;
    cout << solution.isPalindrome(n) << endl;
    return 0;
}
