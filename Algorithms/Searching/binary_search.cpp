#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool binary_search(const vector<T> &arr, const int &val)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = static_cast<int>(floor((left + right) / 2));
        if (arr[mid] == val)
            return true;

        if (arr[mid] < val)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return false;
}

int main(int argc, char **argv)
{

    vector<int> v6{1, 1, 1, 1, 1, 1, 5, 3, 2, 2, 2, 2, 36, 3, 4, 3, 2, 2, 2, 4, 2, 3, 3, 99, 12, 26};
    sort(v6.begin(), v6.end());

    std::cout << binary_search(v6, 100) << '\n';
    std::cout << binary_search(v6, 5) << '\n';

    return 0;
}