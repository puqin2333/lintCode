//
//  main.cpp
//  旋转数组
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/21.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        
        
    }

    
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,4,5,6,7};
    Solution solution;
    int k = 0;
    cin >> k;
    solution.rotate(nums, k);
    for (int  i = 0; i < nums.size(); i ++) {
        cout << nums[i] << endl;
    }
    return 0;
}
