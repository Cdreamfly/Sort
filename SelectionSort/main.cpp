#include <iostream>
#include "SortTextHelper.h"
#include "Student.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}


int main() {
    int n = 100000;
    int *arr = SortTextHelper::generateRandomArray(n, 0, n);
    SortTextHelper::testSort("selectionSort",selectionSort,arr,n);

    delete[] arr;

    Student stu[3] = {{"D", 90},
                      {"C", 100},
                      {"B", 95}};
    /*selectionSort(stu, 3);
    for (int i = 0; i < 3; ++i) {
        cout << stu[i];
    }
    cout << endl;*/

    return 0;
}
