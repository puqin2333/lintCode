//
//  main.cpp
//  array
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/22.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int comp(const void * a, const void * b) {
    return  (* ( int * ) a - * ( int * ) b);
}

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
    // https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/24/
    
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.empty()) {
            return false;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
    // https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/25/
    int singleNumber(vector<int>& nums) {
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            m = nums[i] ^ m;
        }
        return m;
    }
    
    // https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/26/
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersectVector;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int pointNums1 = 0, pointNums2 = 0;
        while (pointNums1 < nums1.size() && pointNums2 < nums2.size()) {
            if (nums1[pointNums1] == nums2[pointNums2]) {
                intersectVector.push_back(nums1[pointNums1]);
                pointNums1++;
                pointNums2++;
            } else if(nums1[pointNums1] < nums2[pointNums2]) {
                pointNums1 ++;
               
            } else {
                pointNums2++;
            }
        }
        return intersectVector;
    }

//    https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/27/
    vector<int> plusOne(vector<int>& digits) {
        unsigned long count = digits.size();
        vector<int> addDigits(count + 1,0);
        for (int i = count-1; i >= 0 ; i--) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }
        addDigits[0] = 1;
        return addDigits;
    }
//    https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/28/
    void moveZeroes(vector<int>& nums) {
        unsigned long count = nums.size();
        int zeroNum=0;
        for(int i=0;i < count;i++){
            if(nums[i]==0) {
                zeroNum++;
            }else if(zeroNum!=0) {
                nums[i-zeroNum]=nums[i];
                nums[i]=0;
            }
        }

    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {0, 1, 0 , 3 ,12};
//    vector<int> nums2 = {2, 2};
    Solution solution;
//    int k = 0;
//    cin >> k;
    solution.moveZeroes(nums);
//    int n = solution.removeDuplicates(nums);
//    cout << solution.singleNumber(nums);
    for (int  i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    
    return 0;
}
