//
//  main.cpp
//  合并排序数组
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/12/5.
//  Copyright © 2017年 Puqin.Chen. All rights reserved.
//

/* 算法描述：
 * 合并两个排序的整数数组A和B变成一个新的数组。
 */
/* 样例
 给出A=[1,2,3,4]，B=[2,4,5,6]，返回 [1,2,2,3,4,4,5,6]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int sizeA = A.size(), sizeB = B.size();
        vector<int> result;
        
        int i = 0, j = 0;
        
        if(sizeA == 0)
            return B;
        else if(sizeB == 0)
            return A;
        
        while(i < sizeA && j < sizeB) {
            if(A[i] < B[j]) {
                result.push_back(A[i]);
                i++;
            }
            else if(A[i] > B[j]) {
                result.push_back(B[j]);
                j++;
            }
            else {
                result.push_back(A[i]);
                i++;
                result.push_back(B[j]);
                j++;
            }
        }
        
        while(i < sizeA) {
            result.push_back(A[i]);
            i++;
        }
        while(j < sizeB) {
            result.push_back(B[j]);
            j++;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    int n,nn,sss;
    cin >> n >> nn;
    vector<int> A;
    vector<int> B;
    for (int i = 0; i < n; i++) {
        cin >> sss;
        A.push_back(sss);
    }
    for (int i = 0; i < nn; i++) {
        cin >> sss;
        B.push_back(sss);
    }
    vector<int> s = solution.mergeSortedArray(A, B);
    vector<int>::iterator m = s.begin();
    while (m != s.end()) {
        cout << *m << endl;
        m++;
    }
    return 0;
}

