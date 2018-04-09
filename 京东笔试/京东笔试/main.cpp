//
//  main.cpp
//  京东笔试
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/9.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//
//硬币
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    string str;
//    cin >> str;
//    int result = 0;
//    for (int i = 0; i < str.length(); i++) {
//        if (i == 0) {
//            if (str[i + 1] != str[i]) {
//                result++;
//            }
//        } else if (i == str.length() - 1) {
//            if (str[i - 1] != str[i]) {
//                result++;
//            }
//        } else {
//            if (str[i] != str[i-1] || str[i] != str[i+1]) {
//                result++;
//            }
//        }
//    }
//    cout << result;
//    return 0;
//}

// 整除
//#include <iostream>
//using namespace std;
//
//long lowestCommonMultiple(int m, int n) {
//    long x, m1, n1;
//    m1 = m;
//    n1 = n;
//    while (n != 0) {
//        x = m % n;
//        m = n;
//        n = x;
//    }
//    return m1*n1 / m;
//}
//int main(int argc, const char * argv[]){
//    int n;
//    long min = 1;
//    long temp;
//    cin >> n;
//    for (int i = 1;i < n; i++) {
//        temp = lowestCommonMultiple(min, i+1);
//        if (temp > min) {
//            min = temp;
//        }
//    }
//    cout << min;
//    return 0;
//}

// 括号匹配
#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]){
    int count;
    cin >> count;
    while (count--) {
        string str;
        cin >> str;
        bool flag = true;
        long len = str.length();
        int result = 0, num = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == '(') {
                result++;
            } else {
                result--;
            }
            if (result < -1) {
                flag = false;
                break;
            } else if (result == -1) {
                num++;
            }
        }
        if (flag && !result && num < 2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}





