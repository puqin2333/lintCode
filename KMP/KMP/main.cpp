//
//  main.cpp
//  KMP
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/21.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

#include <iostream>
using namespace std;

// BF 时间复杂度为O(n*m)
int BFStringSearch(string S, string P){
    int i = 0, j = 0;
    int s_len = (int)S.size();
    int p_len = (int)P.size();
    
    while (i < s_len && j < p_len) {
        if (S[i] == P[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == p_len)
        return i - j;
    
    return -1;
}

// KMP 时间复杂度为O(n+m)
void getNext(string p, int *next) {
    int len = (int)p.size();
    // i 是模式串P的下标，从0开始，在程序中，我们依次求出 next[i]的值
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len) {
        if (j == -1 || p[i] == p[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int KMP(string s, string p, int *next) {
    getNext(p, next);
    int i = 0, j = 0;
    int lenS = (int)s.size();
    int lenP = (int)p.size();
    
    while (i < lenS && j < lenP) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == lenP) {
        return i - j;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int next[100] = { 0 };
    
    cout << KMP("bbc abcdab abcdabcdabde", "abcdabd", next) << endl;
    return 0;
}
