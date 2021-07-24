#include <iostream>
#include "SortTestHelper.h"
#include "selectionSort.h"

using namespace std;

/*template<typename T>
void insertionSort(T arr[], int n)
//  写法1
//  for( int j = i ; j > 0 ; j-- )
//     if( arr[j] < arr[j-1] )
//          swap( arr[j] , arr[j-1] );
//     else
//          break;

    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}*/
//优化交换，因提前终止内层循环,所以对于近乎于有序的数据非常有效
template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        //寻找元素arr[i]合适插入的位置
        T e = arr[i];
        int j;//j保存元素e应该插入的位置
        for (j = i; j > 0 && arr[j - 1] > e; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}


int main() {

    int n = 20000;

    // 测试1 一般测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int *arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试2 有序性更强的测试
    cout<<"Test for more ordered random array, size = "<<n<<", random range [0, 3]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,3);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);

    delete[] arr1;
    delete[] arr2;

    cout<<endl;


    // 测试3 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort", selectionSort,arr2,n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}
