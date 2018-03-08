//
//  main.cpp
//  和为s的连续正数序列
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/8.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

/// 和为s的连续正数序列
/// 题目描述：输入一个正数s，打印出所有和为 s 的连续正数序列。
/// 例如输入15，1+2+3+4+5=4+5+6=7+8=15，要求至少有两个数

#include <iostream>
using namespace std;

class Solution {
public:
    void FindContinuousSequence(int sum) {
        if (sum < 3) { //当sum小于3时，不满足题目直接return
            return;
        }
        int small = 1, big = 2; //sum = small+（small+1） + .... +(big - 1)+big
        int mid = (1 + sum)/2;
        int curSum = small + big;   // curSum 表示当前的和，并与 sum 进行比较
        while (small < mid) {       // 当 small 小于 mid  时，curSum 才会小于 sum，满足题目要求
            if (curSum == sum) {
                printContinuousSequence(small, big);
            }
            while (curSum > sum && small < mid) {
                curSum -= small;
                small++;
                if (curSum == sum) {
                    printContinuousSequence(small, big);
                }
            }
            big++;
            curSum += big;
            
        }
    }
    void printContinuousSequence(int small, int big) {
        for (int i = small; i <= big ; i++) {
            cout << i;
        }
        printf("\n");
    }
    
};

int main(int argc, const char * argv[]) {
    Solution solution;
    int sum = 0;
    cin >> sum;
    solution.FindContinuousSequence(sum);
    return 0;
}
