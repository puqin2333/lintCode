//
//  main.cpp
//  数据流中的第一个唯一的数
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/11/3.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//
/* 算法描述：
 * 给一个连续的数据流,写一个函数返回终止数字到达时的第一个唯一数字（包括终止数字）,如果在终止数字前无唯一数字或者找不到这个终止数字, 返回 -1.
 */
/* 样例
 给一个数据流 [1, 2, 2, 1, 3, 4, 4, 5, 6] 以及一个数字 5, 返回 3
 给一个数据流 [1, 2, 2, 1, 3, 4, 4, 5, 6] 以及一个数字 7, 返回 -1
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param : a continuous stream of numbers
     * @param : a number
     * @return: returns the first unique number
     */
    int firstUniqueNumber(vector<int> nums, int number) {
        // Write your code here
        vector<int>::iterator p = nums.begin();
        int num[10] = {0};
        int flag = 0;
        while(p != nums.end()) {
            if (*p != number) {
                p++;
            } else {
                flag = 1;
                break;
            }
        }
        if (flag != 1) {
            return -1;
        }
        p = nums.begin();
        while(p != nums.end()) {
            num[*p]++;
            p++;

        }
        flag = 0;
        for (int i = 0; i < 10; i++) {
            if(num[i] == 1){
                return i;
            }else {
                flag = 1;
            }
        }
        if (flag != 1) {
            return -1;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    
    vector<int> nums;
    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int b;
    cin >> b;
    
    cout << solution.firstUniqueNumber(nums,b);
    
    
    return 0;
}
