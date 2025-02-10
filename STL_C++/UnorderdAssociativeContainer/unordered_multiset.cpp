#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &out, const unordered_multiset<T> &s)
{
    for (const auto &val : s)
    {
        out << val << ' ';
    }
    return out;
}

int main(int argc, char **argv)
{

    constexpr int ARR_SIZE = 12;
    int arr[ARR_SIZE] = {9, 5, 66, 77, 1, 12, 16, 28, 100, 152, 120, 152};

    unordered_multiset<int> ums(arr, arr + ARR_SIZE);
    cout << ums << '\n';

    ums.insert({1, 3, 6, 11, 1, 1, 1, 1, 1});

    cout << ums.count(1) << '\n';

    cout << ums << '\n';
    return 0;
}