//
//  main.cpp
//  QuickSort
//
//  Created by 满脸胡茬的怪蜀黍 on 2017/12/24.
//  Copyright © 2017年 Puqin.Chen. All rights reserved.
//

/// 快速排序的思路：
///  要求：基准数 flag



#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void Swap(vector<int> &array,int &low,int &high) {
        int temp = array[low];
        array[low] = array[high];
        array[high] = temp;
    }
    void Qsort(vector<int> &array, int low, int high) {
        int flag;
        if (low < high) {
            flag = Partition(array, low, high);
            Qsort(array, low, flag - 1);
            Qsort(array, flag + 1, high);
        }
    }
    int Partition(vector<int> &array, int low, int high) {
        int flag = array[low];
        while (low < high) {
            while (low < high && flag <= array[high])
                high--;
            Swap(array, low, high);
            
            while (low < high && flag >= array[low])
                low++;
            Swap(array, low, high);
        }
        return low;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    int n ,a;
    vector<int> A;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        A.push_back(a);
    }
    solution.Qsort(A, 0,(int) A.size());
    
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
