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
    /* 冒泡排序：又称相邻比邻排序，即在扫描待排序记录序列时，顺次比较相邻两个记录大小，如果逆序就交换位置。
        时间复杂度：最小的时间代价为o(n)，一般为 o(n^2)
        空间复杂度：o(1)
        稳定性：稳定
        优化：设置 flag 标志，用来标志是否进行交换操作，从而跟踪序列是否已经有序。
     */
    void bubbleSort(int *array, int length) {
        int flag = 1,temp = 0;
        for (int i = 0; i < length && flag; i++) {
            flag = 0;
            for (int j = 0; j < length - i; j++) {
                if (array[j] > array[j+1]) {
                    temp = array[j];
                    array[j] = array[j+1];
                    array[j + 1] = temp;
                    flag = 1;
                }
            }
        }
    }
    /* 快速排序：从待排序序列中任意选择一个记录，以该记录的关键字作为“枢纽”，凡其关键字小于枢纽的记录均移动至该记录之前，反之，凡是关键字大于枢轴的记录均移动至该记录之后。致使一趟排序之后，记录的无序序列 r[1..n]  将分割成左右两个子序列，然后分别对分割所得两个子序列递归地进行快速排序，以此类推，直到每个子序列中只含一个记录为止。
        时间复杂度：平均时间复杂度为o(nlog2n)，最差时间复杂度为 o(n^2)
        空间复杂度：o(log2n)
        稳定性：不稳定
        优化：枢轴值的选取
     */
    void qSort(int *array, int low, int high) {
        int flag = 0;
        if (low < high) {
            flag = partition(array, low, high);
            qSort(array, low, flag - 1);
            qSort(array, flag + 1, high);
        }
    }
    
    int partition(int *array, int low, int high) {
        int flag = array[low];
        while (low < high) {
            while (low < high && flag <= array[high] ) {
                high--;
            }
            Swap(array, low, high);
            while (low < high && flag >= array[low] ) {
                low++;
            }
            Swap(array, low, high);
        }
        return low;
    }
    
    void Swap(int *array,int low,int high) {
        int temp = array[low];
        array[low] = array[high];
        array[high] = temp;
    }
    /// 选择类排序：在第i趟的记录序列中选取关键字第 i 小的记录作为有序序列的第 i 个记录。该类算法的关键就在于如何从剩余的待排序序列中找出最小或最大的那个记录。
    /* 简单选择排序：
        时间复杂度：平均时间复杂度为o(nlog2n)，最差时间复杂度为 o(n^2)
        空间复杂度：o(log2n)
        稳定性：不稳定
        优化：枢轴值的选取
     */
};

int main(int argc, const char * argv[]) {
    int array[10] = {27, 8, 32, 11, 14, 6, 9, 18, 31, 88};
    Sort sorts;
    sorts.bubbleSort(array, 10);
    sorts.qSort(array, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << array[i] << endl;
    }
    return 0;
}
