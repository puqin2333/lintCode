//
//  main.cpp
//  循环引用
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/9.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string process(int fileNum, vector<string> array) {
        string result;
        /*
         算法实现是向量里的三个字符串里是否有出现的数字
        */
        for (int i = 0; i < fileNum - 1; i++) {
            for (int j = 1; j < fileNum; j++) {
                
            }
        }
        return result;
    }
}
int main(int argc, const char * argv[]) {
    int fileNum = 0;
    cin >> fileNum;
    vector<string> array;
    for (int i = 0; i < fileNum; i++) {
        string file;
        cin >> file;
        array[i] = file;
    }
    Solution solution;
    cout << solution.process(fileNum, array) << endl;
    return 0;
}
