//
//  main.cpp
//  平方数之和
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/11/2.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

/* 题目描述：
 *给一个整数 c, 你需要判断是否存在两个整数 a 和 b 使得 a^2 + b^2 = c.
 */
/* 样例：
 * 给出 n = 5
   返回 true // 1 * 1 + 2 * 2 = 5
   给出 n = -5
   返回 false
 */
/* 思路分析：
 * 

class Solution {
public:
    /*
     * @param : the given number
     * @return: whether whether there're two integers
     */
    bool checkSumOfSquareNumbers(int num) {
        
//        if (num % 4 == 1) {
//            return true;
//        } else if (num == 0) {
//            return false;
//        }
        
        int a;
        for (int i = 0; i <= sqrt(num); i++) {
            a = i * i;
            if ((int)sqrt(num - a) * (int)sqrt(num - a) + a == num) {
                return true;
            }
//            for (int i = sqrt(num-a); i > 0; i--) {
//                b = i*i;
//                if (a + b == num) {
//                    return true;
//                }
//            }
        }
        return false;
    }
};


int main(int argc, const char * argv[]) {
   
    Solution solution;
    int n;
    cin >> n;
    cout << solution.checkSumOfSquareNumbers(n) << endl;
    return 0;
}
