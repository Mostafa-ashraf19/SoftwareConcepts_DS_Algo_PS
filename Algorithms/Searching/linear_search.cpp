#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool linear_search(const vector<T> &arr, const int &val)
{
    for (const auto &a : arr)
    {
        if (a == val)
            return true;
    }
    return false;
}

int main(int argc, char** argv) {

    vector<int> v6{1, 1, 1, 1, 1, 1, 5, 3, 2, 2, 2, 2, 36, 3, 4, 3, 2, 2, 2, 4, 2, 3, 3, 99, 12, 26};
    std::cout << linear_search(v6, 100) << '\n';
    std::cout << linear_search(v6, 5) << '\n';

    return 0;
}