//
//  main.cpp
//  数组的次大次小
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/25.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int AMax, BMax, AMin, BMin, a;
    vector<int> array;
    for (int i = 0; i < 10; i++) {
        cin >> a;
        array.push_back(a);
    }
    AMax = AMin = array[0];
    for (int i = 0; i < 10; i++) {
        if (AMax < array[i]) {
            AMax = array[i];
        } else if( AMin > array[i]){
            AMin = array[i];
        }
    }
    
    BMax = array[0];
    BMin = AMax;
    for (int i = 0; i < 10; i++) {
        if (BMax < array[i] && AMax != array[i]) {
            BMax = array[i];
        }
        if(BMin > array[i] && AMin != array[i]){
            BMin = array[i];
        }
    }
    cout << "AMax = " << AMax <<  "AMin = " << AMin <<  "BMax = " << BMax <<  "BMin = " << BMin ;
    return 0;
}
