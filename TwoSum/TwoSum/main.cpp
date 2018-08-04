//
//  main.cpp
//  TwoSum
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/2/9.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//


/// 两数之和
///算法描述： 给定一个整数数组，如果存在数组中两个数字的和与输入的特定值相同，则输入这两个数字的下标。您可以假设每个输入都只有一个解决方案，并且您可能不会两次使用相同的元素。
///算法分析：如果我们的思维只是局限在数组中，可能算法的复杂度至少为n的平方，如果我们学过 C++ 的 map,那么问题就可以转化为一个特定值减去map中的一个元素，然后去在当前 map 中查找是否还存在一个被减数。因为我们的map有 key 和对应的 value ，所以我们用key存数组元素的下标，用value存数组元素。
//输入实例：2 7 11 18 20 （数组元素）
//          9            （target）
//输出实例：0 1



#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> subscript;
//        map<int ,int> twoSum;
//        int i = 0;
//        while (i < nums.size()) {
//            twoSum[nums[i]] = i;
//            i++;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            int otherNums = target - nums[i];
//            if (twoSum.count(otherNums) && twoSum[otherNums] != i) {
//                subscript.push_back(i);
//                subscript.push_back(twoSum[otherNums]);
//                break;
//            }
//        }
//        return subscript;
//    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> subScript;
        map<int, int> twoSum;
        int i = 0;
        while(i < nums.size()) {
            twoSum[nums[i]] = i;
            i++;
        }
        for(int j = 0; j < nums.size(); j++) {
            int otherNum = target - nums[j];
            if(twoSum.count(otherNum) && twoSum[otherNum] != j) {
                subScript.push_back(j);
                subScript.push_back(twoSum[otherNum]);
                break;
            }
        }
        return subScript;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int target = 0,i = 0;

    vector<int> nums;
    while (i < 5) {
        int num;
        cin >> num;
        nums.push_back(num);
        i++;
    }
    cin >> target;
    Solution solution ;
    i = 0;
    vector<int> twoSum = solution.twoSum(nums, target);
    while (i < twoSum.size()) {
        cout << twoSum[i] << endl;
        i ++;
    }
    return 0;
}
