#include <bits/stdc++.h>
using namespace std;

// Heapify its a buildMaxHeap but for part of alreadt sorted array, 
// Complete binary tree to max/min-heap conversion.
// i is position to check validate max-heap condition, parent node > child node (left/right)
template<typename T>
void heapify(std::vector<T> &arr, const int& arrSize, int i) {

    // Suppose max position is I postion.
    int max = i;

    int left = 2*i + 1;
    int right = (2*i) + 2;


    if(left < arrSize && arr[left] > arr[max]) {
        max = left;
    }

    if (right < arrSize && arr[right] > arr[max]) { 
        max = right;
    }

    if(max != i) {
        swap(arr[i], arr[max]);
        heapify(arr, arrSize, max);
    }
}

template<typename T>
void buildMaxHeap(std::vector<T> &arr,const int& arrSize) {
    for (int i = arrSize/2 - 1; i >= 0 ; --i)
    {
        heapify(arr, arrSize, i);
    }
}

template<typename T>
void heapSort(std::vector<T> &arr) {
    int arrSize = arr.size();

    // Build max heapify binary tree
    buildMaxHeap<T>(arr, arrSize);
    // Swap, remove, heapify
    for (int  i = arrSize - 1; i > 0; --i)
    {
        // Swap root with last element.
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char** argv) {

    std::vector<int> v{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    // {5,4,3,2};
    // {5,89,8,2,3,1,5,6,2,4,0,1,591,100,256,300};
    //{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    heapSort<int>(v);

    for (const auto &eleme : v)
        cout << eleme << ' ';

    cout << '\n';

    return 0;
}