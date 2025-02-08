#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    std::array<int, 5> arr;
    arr.fill(6);
    std::cout << "arr.max_size()= " << arr.max_size() << '\n';

    arr[4] = 10;
    std::cout << "arr.front()= " << arr.front() << "arr.back()= " << arr.back() << '\n';

    // Swap arr with arr2
    // arr.swap(arr2)

    std::cout << "boolalpha(arr.empty()) " << boolalpha << arr.empty() << '\n';

    // Pointer to first element.
    std::cout << "&arr[0] " << &arr[0] << '\n';
    std::cout << "arr.data() " << arr.data() << '\n'; // &arr[0] equal to arr.data()

    std::cout << std::endl;
    return 0;
}