//
//  main.cpp
//  两个字符串相加
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/18.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    /*
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        // write your code here
        string res = "";
        if (num1.empty()) {
            return num2;
        } else if (num2.empty()) {
            return num1;
        } else {
            int b = (int)num1.length();
            int c = (int)num2.length();
            int temp = 0;
            int a = b > c ? b : c;
            char num3[5100];
            for (int i = a; i >= 0; i--) {
                int s = 0;
                if (b == 0) {
                    s = num2[--c] - '0' + temp;
                    temp = 0;
                } else if (c == 0) {
                    s = num1[--b] - '0' + temp;
                    temp = 0;
                } else {
                    s = num1[--b] + num2[--c] - '0' - '0' + temp;
                    temp = 0;
                }
                if (s >= 10) {
                    temp = s / 10;
                    s = s % 10;
                }
                num3[i] =  s + '0';
                res += num3[i];
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    string n1,n2;
    cin >> n1 >> n2;
    cout << solution.addStrings(n1, n2)<< endl;
    return 0;
}
