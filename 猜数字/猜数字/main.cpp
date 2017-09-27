//
//  main.cpp
//  猜数字
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/12.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
using namespace std;
int m;
int guess(int num);

class Solution {
public:
    /*
     * @param n: An integer
     * @return: how much money you need to have to guarantee a win
     */
    int guessNumber(int n) {
        if (guess(n) == 0) {
            return n;
        }
        int left = 1,right = n;
        while (left < right) {
            int mid = left + (right - left) /2;
            if (guess(mid) == 0) {
                return mid;
            } else if(guess(mid) < 0) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
int guess(int num){
    if (m == num) {
        return 0;
    } else if(m < num) {
        return 1;
    } else {
        return -1;
    }
}
int main(int argc, const char * argv[]) {
    Solution solution;
    int n;
    cin >> n >> m;
    cout << solution.guessNumber(n);
    return 0;
}
