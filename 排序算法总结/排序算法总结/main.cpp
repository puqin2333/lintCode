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
    void biInsertSort(int *array, int length) {
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
        时间复杂度：时间复杂度为 o(n^2)
        空间复杂度：o(1)
        稳定性：不稳定
     */
    void selectSort(int * array, int length) {
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (array[j] < array[i] ) {
                    Swap(array, j, i);
                }
            }
        }
    }
    /* 堆排序：堆的结构类似于完全二叉树，每个结点的值都小于或者等于其左右孩子结点的值，或者每个节点的值都大于或等于其左右孩子的值；堆排序过程将待排序的序列构造成一个堆，选出堆中最大的移走，再把剩余的元素调整成堆，找出最大的再 移走，重复直至有序
        时间复杂度：时间复杂度为 o(nlog2n)
        空间复杂度：o(1)
        稳定性：不稳定
      */
    void heapSort(int *array, int length) {
        for (int i = length / 2 - 1 ; i >= 0; --i ) {
            heapify(array, i , length);
        }
        for (int i = length - 1; i > 0; --i) {
            Swap(array, 0, i);
            heapify(array, 0, i);
        }
    }

    void heapify(int *array, int first, int end) {
        int father = first;
        int son = father * 2 + 1;
        while (son < end) {
            if (son + 1 < end && array[son] < array[son + 1]) {
                son++;
            }
            // 如果父节点大于子节点则表示调整完毕
            if (array[father] > array[son]) {
                break;
            }
            else {
                Swap(array, son, father);
                // 父和子节点变成下一个要比较的位置
                father = son;
                son = father * 2 + 1;
            }
        }
    }
    
    /// 归并排序：首先将原始无序序列划分为两个子序列，然后分别对每个子序列递归地进行排序，最后再将有序子序列合并
    /* 二路归并排序：首先将初始序列的n 个记录看成是n个有序的子序列每个子序列的长度为1，然后两两归并。
        时间复杂度：时间复杂度为 o(nlog2n)
        空间复杂度：o(n)
        稳定性：稳定
     */
    void Merge(int arr[], int reg[], int start, int end) {
        if (start >= end) {
             return;
        }
        int len = end - start, mid = (len >> 1) + start;
        
        int start1 = start, end1 = mid;
        int start2 = mid + 1, end2 = end;
        
        Merge(arr, reg, start1, end1);
        Merge(arr, reg, start2, end2);
        
        
        int k = start;
        
        while (start1 <= end1 && start2 <= end2){
            reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
        }
        
        while (start1 <= end1){
            reg[k++] = arr[start1++];
        }
        while (start2 <= end2){
            reg[k++] = arr[start2++];
        }
        for (k = start; k <= end; k++) {
            arr[k] = reg[k];
        }
    }
    
    void MergeSort(int *array, int length) {
        int  reg[length];
        Merge(array, reg, 0, length - 1);
    }
    
};

int main(int argc, const char * argv[]) {
    int array[10] = {27, 8, 32, 11, 14, 6, 9, 18, 31, 88};
    Sort sorts;
    sorts.heapSort(array, 10);
//    sorts.qSort(array, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << array[i] << endl;
    }
    return 0;
}
