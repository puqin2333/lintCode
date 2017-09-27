//
//  main.cpp
//  各位相加
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/21.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    /*
     * @param num: a positive number
     * @return: true if it's a palindrome or false
     */
    // 递归法
    int getResult(int num) {
        if (num < 10){
            return num;
        }
        int temp = num;
        int sum = 0;
        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }
        return getResult(sum);
    }
    // 数学规律
    int getResult1(int num) {
        if (num < 10) {
            return num;
        }
        int temp = num;
        int sum = 0;
        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }
        int result = num % 9;
        if (result == 0) {
            return 9;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    int n;
    cin >> n;
    cout << solution.getResult1(n) << endl;
    return 0;
}
