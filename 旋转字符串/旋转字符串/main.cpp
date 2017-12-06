//
//  main.cpp
//  旋转字符串
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/12/6.
//  Copyright © 2017年 Puqin.Chen. All rights reserved.
//

/* 算法描述：
 * 给定一个字符串和一个偏移量，根据偏移量旋转字符串(从左向右旋转)
 */
/* 样例
 对于字符串 "abcdefg".
 
 offset=0 => "abcdefg"
 offset=1 => "gabcdef"
 offset=2 => "fgabcde"
 offset=3 => "efgabcd"
 
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        // write your code here
        string offsetString = str;
        if (str == "") {
            return;
        }
        if (offset == 0 ) {
            return;
        }

        int i = 0;
        offset = offset % str.length();
        while (i < str.length()) {
            if (i - offset >= 0) {
                offsetString[i] = str[i - offset];
            } else {
                offsetString[i] = str[i + str.length() - offset];
            }
            i++;
        }
        str = offsetString;
    }
//        char temp;
//        if(offset == 0) return;
//        if(str.length() == 0)return;
//        int len = str.length();
//        for(int i = 1;i <= offset % len;i++){
//            temp = str[len - 1];
//            int j = len-2;
//            while( j >= 0) {
//                str[j + 1] = str[j];
//                j--;
//            }
//            str[0] = temp;
//        }
//    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    string str;
    cin >> str;
    int offset;
    cin >> offset;
    solution.rotateString(str, offset);
    cout << str;
    
    return 0;
}
