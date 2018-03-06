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
        int longLen = (int)max(num1.size(),num2.size());
        int shortLen = (int)min(num1.size(),num2.size());
        string n1 = num1.size() == longLen ? num1:num2;   //长度较长的串
        string n2 = num2.size() == shortLen ? num2:num1;  //长度较短的串
        int diffLen = longLen - shortLen;
        int x =  0;    //进位
        for(int i = shortLen - 1;i >= 0;i--) { //从两个串的末尾开始运算，运算shortLen位
            n1[i+diffLen] = n1[i+diffLen] + n2[i] + x - '0' - '0';
            x = n1[i+diffLen]/10;//保存进位
            n1[i+diffLen] = n1[i+diffLen] % 10 + '0';
        }
        //剩余的部分与进位处理
        //如189+2，先处理9+2 然后在以下运算处理进位与前面18的加法运算
        for(int j = longLen - shortLen - 1; j >= 0; j--) {
            if(x == 0) break;
            n1[j] = n1[j] + x - '0';
            x = n1[j] / 10;//保存进位
            n1[j] = n1[j] % 10 + '0';
        }
        if(x > 0) {
            return '1' + n1;
        }
        else {
            return n1;
        }    
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    string n1,n2;
    cin >> n1 >> n2;
    cout << solution.addStrings(n1, n2)<< endl;
    return 0;
}
