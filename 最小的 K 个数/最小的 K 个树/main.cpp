//
//  main.cpp
//  最小的 K 个树
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/15.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

/// 题目：最小的k个数
/// 描述：输入n个整数，找到其中最小的k个数。例如输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &input, int k) {
        vector<int> array;
        if (input.empty() || k <= 0 || k > input.size()) {
            return array;
        }
        int start = 0;
        int n = (int)input.size();
        int end = n - 1;
        int index = Partition(input, start, end);
        while (index != k - 1) {
            if (index > k-1) {
                end = index - 1;
                index = Partition(input, start, end);
            } else {
                start = index + 1;
                index = Partition(input, start, end);
            }
        }
        for (int i = 0; i < k; i++) {
            array.push_back(input[i]);
        }
        return array;
    }
private:
    int Partition(vector<int> &input, int start, int end){
        int flag = input[start];
        while (start < end) {
            while (start < end && flag <= input[end]) {
                end--;
            }
            Swap(input, start, end);
            while (start < end && flag >= input[start]) {
                start++;
            }
            Swap(input, start, end);
        }
        return start;
    }
    void Swap(vector<int> &array,int &low,int &high) {
        int temp = array[low];
        array[low] = array[high];
        array[high] = temp;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    int n = 0,k = 0;
    cin >> n >> k;
    vector<int> array,kLeastArray;
    while (--n) {
        int c;
        cin >> c;
        array.push_back(c);
    }
    kLeastArray = solution.getLeastNumbers(array, k);
    for (int i = 0; i < k; i++) {
        cout << kLeastArray[i];
    }
    return 0;
}
