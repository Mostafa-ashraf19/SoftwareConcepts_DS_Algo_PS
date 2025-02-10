#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &out, const unordered_set<T> &s)
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

    unordered_set<int> us(arr, arr + ARR_SIZE);
    cout << us << '\n';

    us.insert({1, 3, 6, 11, 1, 1, 1, 1, 1});

    cout << us << '\n';
    return 0;
}