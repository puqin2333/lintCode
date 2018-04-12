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

    int binarySearch(vector<int> &array, int target) {
        // write your code here
        
        int mid = (int )array.size() / 2;
        int start = 0, end = (int)array.size() - 1;
        if (array.size() == 0) {
            return -1;
        }
        while (start <=  end) {
            mid = (start + end) / 2; // 折半查找
            // 插值查找：根据要查找的关键字 key 与查找表只能够最大最小记录的关键字比较后的查找方法，
            // 其核心就是插值公式： (key-a[low])/(a[high]-a[low])
            // mid = start + (target - array[start])/ (array[end] - array[start]);
            if (array[mid] > target) {
                end = mid - 1;
            } else if (array[mid] < target){
                start = mid + 1;
            } else {
                return array[mid];
            }
        }
        return 0;
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

