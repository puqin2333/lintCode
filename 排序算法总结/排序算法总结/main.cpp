//
//  main.cpp
//  排序算法总结
//
//  Created by 满脸胡茬的怪蜀黍 on 2018/3/27.
//  Copyright © 2018年 Puqin.Chen. All rights reserved.
//

#include <iostream>
using namespace std;

class Sort {
public:
    /// 插入类排序：在一个已拍好序的有序序列区内，对待排序的无序序列区中记录逐个进行处理，每一步将一个代排序的记录与同组那些已经拍好序的记录进行比较，然后有序的插入到该有序序列区中
    /* 直接插入排序：利用顺序查找来确定 r[i] 在 r[0...i-1]有序序列区中的插入位置
        时间复杂度：最坏情况下为o(n^2)
        空间复杂度：o(1)
        稳定性：稳定
        优化：判断 r[i] < r[i - 1], 否则不用比较
     */
    void insertSort (int *array, int length) {
        int flag = 0;
        int i = 0, j = 0;
        for (i = 1; i < length; i++) {
            if (array[i] < array[i-1]) {
                flag = array[i];
                for (j = i - 1; flag < array[j]; j--) {
                    array[j+1] = array[j];
                }
                array[j+1] = flag;
            }
        }
    }
    /* 折半插入排序：利用折半查找来确定 r[i] 在 r[0...i-1]有序序列区中的插入位置
        时间复杂度：最坏情况下为o(n^2)
        空间复杂度：o(1)
        稳定性：稳定
        优点：改善了关键字的比较次数
     */
    void BiInsertSort(int *array, int length) {
        int flag = 0;
        int i = 0, j = 0, low = 0, high = 0, mid = 0;
        for (i = 1; i < length; i++) {
            if (array[i] < array[i-1]) {
                flag = array[i];
                low = 0;
                high = i - 1;
                while (low < high) {
                    mid = (low + high) / 2;
                    if (flag < array[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                for (j = i - 1; flag < array[j]; j--) {
                    array[j+1] = array[j];
                }
                array[j+1] = flag;
            }
        }
    }
    /* 希尔排序：又称缩小增量排序，先将整个待排元素序列分割成若干个子序列（由相邻某个“增量”的元素组成的）分别进行直接插入排序，然后依次缩小增量在进行排序，待整个序列中的元素基本有序，在对全体元素进行一次直接插入排序。
        时间复杂度：在于增量的选择，如果增量每次除以2递减，时间复杂度为o(n^2),增量每次除以3可以使时间复杂度降为o(n^3/2)
        空间复杂度：o(1)
        稳定性：不稳定
     */
    void shellSort(int *array, int length) {
        int i, j, increment;
        int temp;
        for (increment = length / 2; increment > 0; increment /= 2) {
            for (i = increment; i < length; i++) {
                temp = array[i];
                for (j = i; j >= increment; j -= increment) {
                    if (array[j - increment] > temp) {
                        array[j] = array[j - increment];
                    } else {
                        break;
                    }
                }
                array[j] = temp;
            }
        }
       
    }
    
    /// 交换类排序：对待排序记录的关键字两两比较，只要发现两个记录为逆序就交换，直到没有逆序的记录为止。冒泡和快排就是交换类排序。
    
    
    
};

int main(int argc, const char * argv[]) {
    int array[10] = {27, 8, 32, 11, 14, 6, 9, 18, 31, 88};
    Sort sorts;
    sorts.shellSort(array, 10);
    for (int i = 0; i < 10; i++) {
        cout << array[i] << endl;
    }
    return 0;
}
