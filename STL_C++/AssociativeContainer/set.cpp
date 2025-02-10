#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &out, const set<T> &s)
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

    set<int> s(arr, arr + ARR_SIZE);
    set<int, std::greater<int>> s2({3, 6, 1 , 1, 1, 4, 6, 66, 4, 65, 26, 1}, std::greater<int>());

    cout << s.count(152) << '\n';

    cout << s2.count(1) << '\n';

    s.insert({3, 1, 3, 5, 6, 2, 2, 2, 6, 10, 36, 88});
    s.insert(3); // one const ref L-value , and other by move R-value ref.
    s.insert(next(s.begin(), 6), 1000);

    std::cout << s << std::endl;

    // remove value, val at iterator(position), and range of value.
    s.erase(3);
    s.erase(s.begin());
    // s.begin() return read only iterator(const)
    s.erase(s.begin(), next(s.begin(), 4));

    // std::set<int>::key_comp comp = s.value_comp();
    // std::cout << typeid(key_comp).name() << '\n';

    // To find element, use count or find(with iterator).
    std::cout << s.count(1000) << std::endl;
    auto is_found = s.find(77); // return end iterator incase of not found value.
    std::cout << "*is_found= " << *is_found << '\n';

    if (s.find(3) == s.end())
    {
        std::cout << "Value not found\n";
    }
    std::cout << *s.end() << '\n';

    std::cout << s << std::endl;
    // std::cout << s2 << std::endl;

    auto res = s.equal_range(3); // reutrn both lower and upper bound.
    std::cout << *res.first << " " << *res.second << '\n';
    std::cout << *s.upper_bound(66) << " " << *s.lower_bound(-1) << '\n';

    std::cout << '\n';

    std::cout << std::endl;
    return 0;
}