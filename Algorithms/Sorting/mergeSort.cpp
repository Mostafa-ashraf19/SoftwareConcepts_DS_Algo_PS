#include <bits/stdc++.h>
using namespace std;

template <typename T>
void merge(std::vector<T> &arr, int l, int m, int r)
{
    int i = 0, j = 0, k = l;

    int sArr1 = m - l + 1;
    int sArr2 = r - m;
    std::vector<T> arr1(sArr1);
    std::vector<T> arr2(sArr2);

    // Fill elements from left to middle number in new subarray.
    for (int a = 0; a < sArr1; a++)
    {
        arr1[a] = arr[l + a];
    }
    // Fill elements from middle to right number in new subarray.
    for (int b = 0; b < sArr1; b++)
    {
        arr2[b] = arr[m + 1 + b];
    }

    
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            ++i;
        }
        else
        {
            arr[k] = arr2[j];
            ++j;
        }
        ++k;
    }
    while (i < arr1.size())
    {
        arr[k++] = arr1[i++];
    }
    while (j < arr2.size())
    {
        arr[k++] = arr2[j++];
    }
}

template <typename T>
void mergeSort(std::vector<T> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(int argc, char **argv)
{
    std::vector<int> v{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    mergeSort<int>(v, 0, v.size() - 1);

    for (const auto &eleme : v)
        cout << eleme << ' ';

    cout << '\n';
    return 0;
}