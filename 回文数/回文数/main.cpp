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
    bool isPalindromeString(int num) {
        if (num < 0 || (num % 10 == 0 && num != 0)) {
            return false;
        }
        string s = to_string(num);
        int length = (int)s.length();
        for (int i = 0; i < length/2; i++) {
            if (s[i] != s[length - i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    bool isPalindromeReverse(int num) {
        if (num < 0 || (num % 10 == 0 && num != 0)) {
            return false;
        }
        int reverseNum = 0;
        while (num > reverseNum) {
            reverseNum *= 10;
            reverseNum += num % 10;
            num /= 10;
        }
        return num == reverseNum || num == reverseNum / 10;
    }

};

int main(int argc, const char * argv[]) {
    Solution solution;
    int n;
    cin >> n;
    cout << solution.isPalindromeString(n) << endl;
    cout << solution.isPalindromeReverse(n) << endl;
    return 0;
}
