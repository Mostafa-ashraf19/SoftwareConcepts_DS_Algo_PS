#include <bits/stdc++.h>
using namespace std;

// Prefix Sum
std::vector<int> prefixSum(const std::vector<int> &arr)
{
    std::vector<int> prefix(arr.size());

    // {10, 20, 10, 5, 15}
    // {10, 30, 40, 45, 60}

    prefix[0] = arr[0];
    for (int i = 1; i < (int)arr.size(); i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return std::move(prefix);
}

int main(int argc, char **argv)
{

    auto res = prefixSum({10, 20, 10, 5, 15});
    for(auto v : res)
        std::cout << v << ' ' ;
    std::cout << '\n';
    return 0;
}