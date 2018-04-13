//
//  main.cpp
//  二进制数中的1的个数
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/13.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> array(num + 1, 0);
        for (int i = 0; i <= num; i++) {
            array[i] = NumberOf1(i);
        }
        return array;
    }
private:
    int NumberOf1(int n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
            if (n & flag) {
                count++;
            }
            flag = flag << 1;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    vector<int> array;
    Solution solution;
    array = solution.countBits(num);
    for (int i = 0; i <= num; i++) {
        cout << array[i] << endl;
    }
    
    return 0;
}
