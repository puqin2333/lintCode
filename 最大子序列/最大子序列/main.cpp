//
//  main.cpp
//  最大子序列
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/7.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//
/// 题目描述：
/// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

/// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
/// the contiguous subarray [4,-1,2,1] has the largest sum = 6.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> & nums) {
        int sum = 0,maxSum = nums[0];
        vector<int> sumArray;
        for (int i = 0; i < nums.size() ; i++) {
            sum += nums[i];
            if (sum > maxSum) {
                maxSum = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums;
    int c = 0;
    cin >> c;
    while (c != 0) {
        nums.push_back(c);
        cin >> c;
    }
    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}
