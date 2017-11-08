//
//  main.cpp
//  缺少的字符串
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/11/8.
//  Copyright © 2017年 满脸胡茬的怪蜀黍. All rights reserved.
//

/* 算法描述：
 * 给出两个字符串，你需要找到缺少的字符串
 */
/* 样例
 给一个字符串 str1 = This is an example, 给出另一个字符串 str2 = is example
 返回 ["This", "an"]
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param : a given string
     * @param : another given string
     * @return: An array of missing string
     */
    vector<string> missingString(string str1, string str2) {
        // Write your code here
        vector<string> s;
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] == ' ') {
                
            }
        }
        return s;
    }
};
int main(int argc, const char * argv[]) {
    
    Solution solution;
    string str1,str2;
    getline(cin, str1, '\n');
    getline(cin, str2, '\n');
    
    vector<string> s = solution.missingString(str1, str2);
    vector<string>::iterator p = s.begin();
    while(p != s.end()) {
        cout << *p;
        p++;
    }
    return 0;
}

