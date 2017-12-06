//
//  main.cpp
//  丑数2
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/11/27.
//  Copyright © 2017年 Puqin.Chen. All rights reserved.
//

/* 算法描述：
 *设计一个算法，找出只含素因子2，3，5 的第 n 小的数。
 
 符合条件的数如：1, 2, 3, 4, 5, 6, 8, 9, 10, 12...
 */
/* 样例
 例如n=12，k=1，在 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]，我们发现1出现了5次 (1, 10, 11, 12)
 */

#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        int count = 0;
        int m = 0;
        while(count < n)
        {
            m++;
            int number = m;
            while(number % 2 == 0)
                number = number / 2;
            while(number % 3 == 0)
                number = number / 3;
            while(number % 5 == 0)
                number = number / 5;
            if(number == 1)
            {
                count++;
            }
        }
        return m;
    }
};
int main(int argc, const char * argv[]) {
    
    Solution solution;
    int n;
    cin >> n;
    cout << solution.nthUglyNumber(n) << endl;
    return 0;
}
