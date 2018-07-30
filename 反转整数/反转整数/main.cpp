//
//  main.cpp
//  反转整数
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/27.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//


/// reverse integer
/// 题目描述：给定一个32位带符号整数，翻转该整数
/// 题目思考：该题可以转化为简单的分解与组合整数的每一位的数字。需要注意的是32位带符号整数的溢出问题


#include <iostream>
using namespace std;

class Solution {
public:
    int reserveNumber(int num) {
        long reserveNum = 0;
        int temp = abs(num);
        while (temp > 0) {
            reserveNum *= 10;
            reserveNum += temp % 10;
            if (reserveNum > INT_MAX ) {
                return 0;
            }
            temp /= 10;
        }
        return (int)(num >= 0 ? reserveNum :-reserveNum);
    }
};

int main(int argc, const char * argv[]) {
    
//    Solution solution;
//
//    int n;
//    cin >> n;
//    cout << solution.reserveNumber(n) << endl;
    char *p;
    char s[] = "hi,sdfsf sdf";
    p = s;
    p += 6;
    cout << p ;
    
    return 0;
}
