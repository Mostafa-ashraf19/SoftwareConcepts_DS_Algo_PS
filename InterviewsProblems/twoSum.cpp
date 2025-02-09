#include <bits/stdc++.h>
using namespace std;

// We can solve this by unorderd_map or two pointers
std::pair<int, int> twoSum(const std::vector<int> &arr, int target)
{
    // arr=[2,7,11,15] target=9
    // Two pointers
    int l = 0, r = arr.size() - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] < target)
        {
            ++l;
        }
        else if (arr[l] + arr[r] > target)
        {
            --r;
        }
        else
        {
            return std::make_pair(l, r);
        }
    }
    return std::make_pair(-1, -1);
}

int main(int argc, char **argv)
{

    auto res = twoSum({7, 1, 2, 15}, 9);
    std::cout << res.first << " " << res.second << '\n';

    res = twoSum({2, 7, 11, 15}, 99);
    std::cout << res.first << " " << res.second << '\n';

    return 0;
}