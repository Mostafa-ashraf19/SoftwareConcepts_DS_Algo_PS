#include <bits/stdc++.h>
using namespace std;

// Quick sort same as merge sort with space complexity O(1)
// Choose Pivot

template <typename T>
int partitioning(std::vector<T> &arr, int l, int r)
{

    int pivLocation = l;
    while (true)
    {
        while (arr[pivLocation] <= arr[r] && pivLocation != r)
        {
            --r;
        }
        if (pivLocation == r)
            break;
        else if (arr[pivLocation] > arr[r])
        {
            std::swap(arr[pivLocation], arr[r]);
                pivLocation = r;
        }
        while (arr[pivLocation] >= arr[l] && pivLocation != r)
        {
            ++l;
        }
        if (pivLocation == l)
            break;
        else if (arr[pivLocation] < arr[l])
        {
            std::swap(arr[pivLocation], arr[l]);
            pivLocation = l;
        }
    }

    return pivLocation;
}

template <typename T>
int partitioning2(std::vector<T> &arr, int l, int r) {
    int pivot = arr[r];

    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] <= pivot) {
            ++i;

            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[r]);
    return i + 1;
}

template <typename T>
void quickSort(std::vector<T> &arr, int l, int r)
{
    if (l < r)
    {
        int pivLocation = partitioning2(arr, l, r);
        quickSort(arr, l, pivLocation - 1);
        quickSort(arr, pivLocation + 1, r);
    }
}

int main(int argc, char **argv)
{

    std::vector<int> v{5,4,3,2};
    // {5,89,8,2,3,1,5,6,2,4,0,1,591,100,256,300};
    //{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    quickSort<int>(v, 0, v.size() - 1);

    for (const auto &eleme : v)
        cout << eleme << ' ';

    cout << '\n';
    return 0;
}