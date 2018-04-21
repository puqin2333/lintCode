//
//  main.cpp
//  买卖股票
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/4/21.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int priceSpread = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            int s = prices[i + 1] - prices[i];
            if (s > 0) {
                priceSpread += s;
            }
        }
        return priceSpread;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
