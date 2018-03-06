//
//  main.cpp
//  1出现的次数
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/5.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

/// 题目：从1到n整数中出现1的次数
/// 题目描述：输入一个整数n，求从1 到 n 这 n 个整数的十进制表示中1出现的次数。例如输入12 ，从1到12这些整数中包含1的数字有1，10，11，12。其中，1一共出现5次。
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int numberOf1Between1AndN(unsigned int n) {
        int number = 0;
        for (unsigned int i = 1; i <= n; ++i) {
            number += numberOf1(i);
        }
        return number;
    }
    int numberOf1(unsigned int n) {
        int number = 0;
        while (n) {
            if (n % 10 == 1) {
                number++;
            }
            n /= 10;
        }
        return number;
    }
    /// 数学方法，时间复杂度为log(n)
//    int numberOf1Between1AndN_quick(unsigned int number) {
//        string s = to_string(number);
//        return numberOf1_quick(s);
//    }
//    int numberOf1_quick(string s){
//        if (!s || s < '0' || s > '9') {
//            <#statements#>
//        }
//    }
};

int main(int argc, const char * argv[]) {
    int number = 0;
    cin >> number;
    Solution solution;
    cout << solution.numberOf1Between1AndN(number) << endl;
    return 0;
}
