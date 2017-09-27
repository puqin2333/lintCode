//
//  main.cpp
//  尾部的零
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/9/5.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string>

using namespace std;
// 因为没有考虑数值越界的问题，导致通过只有33%
//class Solution {
//public:
//    long long trailingZeros(long long n) {
//        long long s = 1,count = 0;
//        for(long long i = n; i > 0; i--) {
//            s = s * i;
//        }
//        stringstream ss;
//        ss << s;
//        string numberStr = ss.str();
//        cout << numberStr << '\n';
//        while (1){
//            n=numberStr.find('0');
//            if (n!=-1){
//                numberStr = numberStr.
//                count++;
//            }
//            else break;
//        }
//        return count;
//    }
//};

// 参考网上，将这个问题转换为数学问题，通过分解因子，将其转换能被 2 和 5 整除的数（其实就是能够被 5 整除的个数就是问题的答案）
class Solution {
public:
    long long trailingZeros(long long n) {
        long long count = 0;
        for (int i = 1; pow(5, i) <= n; i++) {
            count += n / (long)pow(5, i);
        }
        return count;
    }
};


int main(int argc, const char * argv[]) {
    Solution solution;
    long n;
    cin >> n;
    cout << "trailingZeros is " << solution.trailingZeros(n) << endl;
    return 0;
}
