//
//  main.cpp
//  最长回文数
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/12.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    /*
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string s) {
        int sum = 0;
        int *letterCount = new int[60];
        string::iterator p = s.begin();
        while (p != s.end()) {
            letterCount[*p - 'A']++;
        }
        while (*letterCount != '\0') {
            if(*letterCount !=0 && *letterCount % 2 == 0)  {
                sum += *letterCount;
            }
        }
        return sum;
    }
};
int main(int argc, const char * argv[]) {
    
    return 0;
}
