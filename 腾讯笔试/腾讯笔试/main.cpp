//
//  main.cpp
//  腾讯笔试
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/5.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//


// 第一题
#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int n, m , count = 0;
    char temp;
    int arr[50][50];
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'X') {
                continue;
            }
            count++;
            temp = arr[i][j];
            int x = i, y = j;
            while (x < n && y < m && arr[x][y] != 'X') {
                if (arr[x][y] == 'X') {
                    break;
                } else if (temp == 'B') {
                    if (arr[x][y] == 'G') {
                        arr[x][y] = 'Y';
                    } else {
                        arr[x][y] = 'X';
                    }
                    x = y + 1;
                    y = y - 1;
                } else if (temp == 'Y') {
                    if (arr[x][y] == 'G') {
                        arr[x][y] = 'B';
                    } else {
                        arr[x][y] = 'X';
                    }
                    x = y + 1;
                    y = y + 1;
                }
            }
        }
    }
    cout << count << endl;
}

// 第二题

//#include <iostream>
//#include <math.h>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    int n, m;
//    int a = 1, b = 0, c = 0;
//    cin >> n >> m;
//    while(1){
//        b = a * (1 - pow(0.5, n)) * 2;
//        if(b > m){
//            a--;
//            break;
//        }
//        a++;
//    }
//    c = a*pow(2, n-1);
//    cout << a << endl;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//
//int consume(int m, int n) {
//    int res = 0;
//    for (int i = 0; i < n; i++) {
//        res += m;
//        m = m % 2 == 0 ? m / 2 : m / 2 + 1;
//    }
//    return res;
//}
//int main(int argc, const char * argv[]) {
//    int n, m;
//    cin >> n >> m;
//    int mm = m / 2;
//    int left = 0;
//    int right = m;
//    int res = 0;
//    while ((right - left) > 1) {
//        int con = consume(mm, n);
//        if (con <= m) {
//            res = mm;
//            left = mm;
//            mm = (mm + right) / 2;
//        } else {
//            right = mm;
//            mm = (mm + left) / 2;
//        }
//    }
//    cout << res << endl;
//    return 0;
//}


// 第三题
/*
#include <iostream>

using namespace std;

int comp(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}

int main(int argc, const char * argv[]) {
    int a[100000];
    int m, j;
    int nn = 0, yy = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    qsort(&a, m, sizeof(int), comp);
    
    j = m - 1;
    while (j >= 0) {
        nn += a[j];
        j--;
        if (j < 0) {
            break;
        }
        
        yy += a[j];
        j--;
    }
    
    cout << nn - yy << endl;
    return 0;
}
 */
