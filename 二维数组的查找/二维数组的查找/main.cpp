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
//        int rowSize = (int)array.size() - 1;
//        int lowSize = (int)array[1].size() - 1;
//        int row = 0;
//        while (row < rowSize && row) {
//            <#statements#>
//        }
        for (int i = 0;i < array.size() ;i++) {
            for (int j = array[i].size() - 1; j >= 0; j--) {
                if (target == array[i][j]) {
                    return true;
                }
            }
        }
        return false;
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

