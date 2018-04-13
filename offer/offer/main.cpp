//
//  main.cpp
//  offer
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/27.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

//
//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//class Solution {
//public:
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
//};
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    int target = 0,i = 0;
//
//    vector<int> nums;
//    while (i < 5) {
//        int num;
//        cin >> num;
//        nums.push_back(num);
//        i++;
//    }
//    cin >> target;
//    Solution solution ;
//    i = 0;
//    vector<int> twoSum = solution.twoSum(nums, target);
//    while (i < twoSum.size()) {
//        cout << twoSum[i] << endl;
//        i ++;
//    }
//    return 0;
//}
// 牛牛迷路
//#include <stdio.h>
//int main(void)
//{
//    int n, j = 0;
//    char str[1002];
//    char arr[5] = {'N', 'E', 'S', 'W'};
//    scanf("%d", &n);
//    scanf("%s", str);
//    for (int i = 0; i < n; i++) {
//        if (j == 0 && str[i] == 'L') {
//            j = 3;
//            continue;
//        } else if (j == 3 && str[i] == 'R') {
//            j = 0;
//            continue;
//        }
//        if (str[i] == 'L') {
//            j--;
//            continue;
//        } else {
//            j++;
//            continue;
//        }
//    }
//    printf("%c\n", arr[j]);
//    return 0;
//}
//被3整除
//#include <stdio.h>
//
//int main(void)
//{
//    int l = 0,r = 0;
//    int sum = 0;
//    int i = 0;
//    scanf("%d %d",&l,&r);
//    int k = 1;
//    while(k <= r) {
//        int m = k;
//        while(m) {
//            sum += (m % 10);
//            m /= 10;
//        }
//        if(sum % 3 == 0 && k >= l){
//            i++;
//        }
//        k++;
//    }
//    printf("%d\n",i);
//    return 0;
//}

#include <stdio.h>
#include <math.h>

int main(void) {
    int t, r, g, b;
    scanf("%d", &t);
    while (t > 0 ) {
        scanf("%d %d %d", &r, &g, &b);
        int x = (r + g + b) / 3;
//        if (abs(r - g)  > 1 || abs(g - b) > 1 || abs(r - b) > 1) {
//            int  x
//        }
        printf("%d\n",x);
        t--;
    }
    return 0;
}

