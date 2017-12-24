//
//  main.cpp
//  二分查找
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/12/7.
//  Copyright © 2017年 Puqin.Chen. All rights reserved.
//

/* 算法描述：
 * 给定一个排序的整数数组（升序）和一个要查找的整数target，
    用O(logn)的时间查找到target第一次出现的下标（从0开始），
    如果target不存在于数组中，返回-1。
 */
/* 样例
 在数组 [1, 2, 3, 3, 4, 5, 10] 中二分查找3，返回2。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        
        int mid = array.size() / 2;
        int start = 0, end = array.size() - 1;
        if (array.size() == 0) {
            return -1;
        }
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (array[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (array[start] == target) {
            return start;
        }
        if (array[end] == target) {
            return end;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    int n = 0, a;
    vector<int> A;
    vector<int> B;
   
    for (int i = 0; i < 7; i++) {
        cin >> a;
        A.push_back(a);
    }
    cin >> n;

    cout << solution.binarySearch(A, n);
    return 0;
}

