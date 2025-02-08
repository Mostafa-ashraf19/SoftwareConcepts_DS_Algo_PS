#include <bits/stdc++.h>
using namespace std;

namespace own
{

    template <typename T>
    struct greater
    {
        bool operator()(const T &a, const T &b) const
        {
            return a < b;
        }
    };

    template <typename T>
    struct less
    {
        bool operator()(const T &a, const T &b) const
        {
            return a > b;
        }
    };
}
// In-place Algorithm - Swap with min/max
// Time Complexity O(n^2)
template <typename T>
void selectionSort(std::vector<T> &arr, const std::function<bool(const T &, const T &)> &func)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (func(arr[i], arr[j]))
                std::swap(arr[i], arr[j]);
        }
    }
}

int main(int argc, char **argv)
{
    std::vector<int> v{5, 7, 9, 5, 8, 9, 6, 4, 2, 31, 2, 0, 23, 62, 1};
    selectionSort<int>(v, own::less<int>());

    for (const auto &eleme : v)
        cout << eleme << ' ';

    cout << '\n';
    return 0;
}