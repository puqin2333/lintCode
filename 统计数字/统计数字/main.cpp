//
//  main.cpp
//  统计数字
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/11/27.
//  Copyright © 2017年 Puqin.Chen. All rights reserved.
//

/* 算法描述：
 * 计算数字k在0到n中的出现的次数，k可能是0~9的一个值
 */
/* 样例
 例如n=12，k=1，在 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]，我们发现1出现了5次 (1, 10, 11, 12)
 */
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count = 0;
        char s = k + '0';
        if (k == 0 && n == 0) {
            return 1;
        }
        for (int i = 0; i <= n; i++) {
            stringstream ss;
            string str;
            ss << i;
            ss >> str;
            int j = 0;
            while ( j < str.length()) {
                if (s == str[j]) {
                    count ++;
                }
                j++;
            }
        }
        return count;
    }
};
int main(int argc, const char * argv[]) {

    Solution solution;
    int k,n;
    cin >> k >> n;
    cout << solution.digitCounts(k, n) << endl;
    return 0;
}

