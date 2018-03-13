//
//  main.cpp
//  数字组合
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/13.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

/// 算法题目：数字组合
/// 题目描述：给两个整型数字 n 和 k ,返回所有长度为k的从1到n的数字组合。要求：数字不能重复。
/// 算法输入： n = 4 ,k = 2
    /*输出：
        1   2
        1   3
        1   4
        2   3
        2   4
        3   4
     */
/// 算法分析：首先读懂该题的题目较为关键，如果你能够想到题目要求的返回值是一个二维数组，那么你就基本读懂题目了。k 就是它的列数。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combineArray;
        /// 第一步：我们可以定义一个大小为k的数组，初始值设为0；
        vector<int> array(k,0);
        /// i 的值即作为 数组下标，也作为判断条件。循环里巧妙的使用 i 是算法的关键。
        int i = 0;
    
        while (i >= 0) {
            /// 每次循环先将array[i]的元素自增
            array[i]++;
            /// 判断 array[i] 的值是否大于n，如果符合，我们就将数字下标前移
            if (array[i] > n) {
                --i;
            } else if (i == k-1) { /// i 如果为数组最后一个下标时，就将数组存入 二维数组
                combineArray.push_back(array);
            } else { ///如果上述都不满足，则继续自增 i,并且让当前的数组元素等于上一个数组元素，因为下一次循环会首先自增。
                ++i;
                array[i] = array[i-1];
            }
        }
        return combineArray;
    }

};
int main(int argc, const char * argv[]) {
    int k ,n;
    cin >> n >> k;
    Solution solution;
    vector<vector<int>> result = solution.combine(n, k);
//    cout << result.size() ;
    for(int i = 0; i < result.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    return 0;
}

