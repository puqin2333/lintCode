//
//  main.cpp
//  数组中超过次数一半的数字
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/9.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

/// 数组中出现次数超过一半的数字
/// 题目描述：数组中有一个数字出现的次数超过数组长度一半，请找出这个数字。
/// 例如，输入一个长度为9的数组{1,2,3,2,2,2,5,4,2},由于数字2出现了5次，超出数组长度的一半，因此输出2。

/// 分析：因为目标值在数组中出现的次数超过其他数组元素的总和，因此，我们可以假设让result表示目标值，numsTime 表示该result出现的次数。我们遍历数组，如果result与当前的数组元素相同，则numTimes++,反之减1.当numsTime 等于0 的时候，我们让 result 等于 当前数组元素，重新计数。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum(vector<int> &array) {
        if (array.size() <= 0 ) {
            return 0;
        }
        
        int result = array[0];
        int timeOfNum = 1;
        for (int i = 1; i < array.size(); i++) {
            if (timeOfNum == 0) {
                result = array[i];
                timeOfNum = 1;
            }
            if (array[i] != result) {
                timeOfNum--;
            } else {
                timeOfNum++;
            }
        }
        if (!isResultMoreThanHalf(array, result)) {
            return 0;
        }
        return result;
    }
    bool isResultMoreThanHalf(vector<int> array,int result) {
        int times = 0;
        for (int i = 0; i < array.size(); i++) {
            if (result == array[i]) {
                times++;
            }
        }
        if (array.size()/ 2 < times) {
            return true;
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> array;
    int arraySize = 0;
    cin >> arraySize;
    for (int i = 0; i < arraySize; i++) {
        int a ;
        cin >> a;
        array.push_back(a);
    }
    Solution solution;
    cout << solution.MoreThanHalfNum(array) << endl;
    return 0;
}
