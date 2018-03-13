//
//  main.cpp
//  爬楼梯
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/12.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//
///题目： 爬楼梯
/// 题目描述：你在爬楼梯。需要n个步骤才能到达顶部。每一次你可以爬1或2步。有多少种不同的方法可以爬到顶端?
#include <iostream>
using namespace std;

class Solution {
public:
    /// 斐波那契数列的解决方案：但是效率太低
    int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        }
        int step = 0;
        step = (int)stepCount(n);
        return step;
    }
    long stepCount(int n) {
        if (n < 2) {
            return 1;
        }
        return stepCount(n - 1) + stepCount(n - 2);
    }
    /// 一趟 while 循环算法，从下往上计算
    ///
    int climbStairsFast(int n) {
        if (n <= 0) {
            return 0;
        }
        int stepSum = 1, stepNext = 1;
        while (n--) {
            stepNext += stepSum;
            stepSum = stepNext - stepSum;
            if (n <= 0) {
                break;
            }
        }
        return stepSum;
    }
};

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    Solution solution;
    cout << solution.climbStairsFast(n);
    return 0;
}
