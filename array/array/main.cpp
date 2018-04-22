//
//  main.cpp
//  array
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/22.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    // 题目链接 https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/23/
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        k = k % n;
        reserve(nums, 0, n -1);
        reserve(nums, 0, k -1);
        reserve(nums, k, n -1);
    }
    void reserve(vector<int>& nums, int start, int end) {
        int temp = 0;
        while (start < end) {
            temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    // 题目链接 https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/22/
    int maxProfit(vector<int>& prices) {
        int priceSpread = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            int s = prices[i + 1] - prices[i];
            if (s > 0) {
                priceSpread += s;
            }
        }
        return priceSpread;
    }
    // https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/21/
    int removeDuplicates(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size() ; i++ ) {
            if (nums[i] != nums[num]) {
                num++;
                nums[num] = nums[i];
            }
        }
        return num + 1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2,2,3,6,7};
    Solution solution;
//    int k = 0;
//    cin >> k;
//    solution.rotate(nums, k);
    int n = solution.removeDuplicates(nums);
    for (int  i = 0; i < n; i ++) {
        cout << nums[i] << endl;
    }
    return 0;
}
