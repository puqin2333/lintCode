//
//  main.cpp
//  二维数组的查找
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/11/28.
//  Copyright © 2017年 Puqin.Chen. All rights reserved.
//



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {

        for (int i = 0;i < array.size() ;i++) {
            for (int j = array[i].size() - 1; j >= 0; j--) {
                if (target == array[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }
    /** 旋转图像，
    给定一个 n × n 的二维矩阵表示一个图像。
    将图像顺时针旋转 90 度。
    https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/1/array/31/
    **/
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++ ) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
    
};
int main(int argc, const char * argv[]) {
    
    Solution solution;
    vector<vector<int>> array(4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int num = 0;
            cin >> num;
            array[i][j] = num;
        }
    }
    int n;
    cin >> n;

    cout << solution.Find(n, array) << endl;
    return 0;
}

