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
    int brinaryGap(int num) {
        int maxDistance = 0;
        vector<int> array;
        ScriptOf1(num, array);
        if (array.size() <= 1) {
            return 0;
        }
        for (int i = 0; i < array.size() - 1; i++) {
            int n = array[i+1] - array[i];
            if (n > maxDistance) {
                maxDistance = n;
            }
        }
        return maxDistance;
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
    void ScriptOf1(int n, vector<int> &array) {
        int script = 0;
        unsigned int flag = 1;
        while (flag) {
            if (n & flag) {
                array.push_back(script);
            }
            flag = flag << 1;
            script++;
        }

    }
};

int main(int argc, const char * argv[]) {
    int num;
    cin >> num;
    vector<int> array;
    Solution solution;
//    array = solution.countBits(num);
//    for (int i = 0; i <= num; i++) {
//        cout << array[i] << endl;
//    }
    cout << solution.brinaryGap(num) << endl;
    
    return 0;
}
