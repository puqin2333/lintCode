//
//  main.cpp
//  反转整数
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/27.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
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
    Solution solution;
    int n;
    cin >> n;
    cout << solution.reserveNumber(n) << endl;
    return 0;
}
