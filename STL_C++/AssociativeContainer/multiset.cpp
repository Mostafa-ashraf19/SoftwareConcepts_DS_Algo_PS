#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &out, const multiset<T> &s)
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

    multiset<int> ms(arr, arr + ARR_SIZE);
    multiset<int, std::greater<int>> ms2({3, 6, 1 , 1, 1, 4, 6, 66, 4, 65, 26, 1}, std::greater<int>());

    cout << ms.count(152) << '\n';

    cout << ms2.count(1) << '\n';

    ms.insert({3, 1, 3, 5, 6, 2, 2, 2, 6, 10, 36, 88});
    ms.insert(3); // one const ref L-value , and other by move R-value ref.
    ms.insert(next(ms.begin(), 6), 1000);

    std::cout << ms << std::endl;

    // remove all the occurrences values, val at iterator(position), and range of value.
    ms.erase(3);
    ms.erase(ms.begin());
    // ms.begin() return read only iterator(const)
    ms.erase(ms.begin(), next(ms.begin(), 4));

    // std::set<int>::key_comp comp = ms.value_comp();
    // std::cout << typeid(key_comp).name() << '\n';

    // To find element, use count or find(with iterator).
    std::cout << ms.count(1000) << std::endl;
    auto is_found = ms.find(77); // return end iterator incase of not found value.
    std::cout << "*is_found= " << *is_found << '\n';

    if (ms.find(3) == ms.end())
    {
        std::cout << "Value not found\n";
    }
    std::cout << *ms.end() << '\n';

    std::cout << ms << std::endl;
    // std::cout << s2 << std::endl;

    auto res = ms.equal_range(3); // reutrn both lower and upper bound.
    std::cout << *res.first << " " << *res.second << '\n';
    std::cout << *ms.upper_bound(66) << " " << *ms.lower_bound(-1) << '\n';

    std::cout << ms.count(5) << '\n';
    std::cout << ms.count(6) << '\n';

    std::cout << '\n';

    std::cout << std::endl;
    return 0;
}