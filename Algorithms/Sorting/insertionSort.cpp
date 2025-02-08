#include <bits/stdc++.h>
using namespace std;

// In-place Algorithm - Shift n elements and Swap
// Time Complexity Best O(n) , Avrg and worset O(n^2)
// Sort from left to right
template <typename T>
void insertionSort(std::vector<T> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    // 80 | 90 60 30 50 70 40 --> i = 1
    // 80 90 | 60 30 50 70 40 --> i = 2
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char **argv)
{
    std::vector<int> v{5, 7, 9, 5, 8, 9, 6, 4, 2, 31, 2, 0, 23, 62, 1};
    insertionSort<int>(v);

    for (const auto &eleme : v)
        cout << eleme << ' ';

    cout << '\n';
    return 0;
}