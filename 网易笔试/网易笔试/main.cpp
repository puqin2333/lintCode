//
//  main.cpp
//  网易笔试
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/8/11.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

// 第一题： 表达式求值
//#include <iostream>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    int a, b, c, max;
//    cin >> a >> b >> c;
//    if ((a==1&&b==1)||(a==1&&c==1)||(b==1&&c==1)){
//        max = a + b + c;
//    } else if(a == 1){
//        max = (a + b) * c;
//    } else if(b==1){
//        max = (a > c ? a : c)*((a > c?c : a) + b);
//    } else if(c == 1){
//        max = (b + c) * a;
//    } else {
//        max = a * b * c;
//    }
//    cout << max;
//    return 0;
//}

// 第二题
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main(int argc, const char * argv[]) {
//    int n , k;
//    int max = 0;
//    int maxi = 0;
//    int sum = 0;
//    vector<int> interestScore;
//    vector<int> isSleep;
//    vector<int> iswake;
//    cin >> n >> k;
//    int a;
//    for (int i = 0; i < n; i++) {
//        cin >> a;
//        interestScore.push_back(a);
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> a;
//        isSleep.push_back(a);
//    }
//    
//    for (int i = 0; i < n; i++) {
//        iswake = isSleep;
//        if (isSleep[i] == 0) {
//            maxi = 0;
//            for (int j = 0; j < k; j++) {
//                iswake[j+i] = 1;
//            }
//            for (int k = 0; k < n; k++) {
//                if (iswake[k] == 1) {
//                    maxi += interestScore[k];
//                }
//                if (maxi > max) {
//                    max = maxi;
//                }
//            }
//        }
//    }
//    sum += max;
//    cout << sum << endl;
//    return 0;
//}

//
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n , m;
    vector<int> appleNum;
    vector<int> queen;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        appleNum.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        queen.push_back(a);
    }
    return 0;
}

