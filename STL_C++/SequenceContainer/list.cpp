#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    constexpr int ARR_SIZE = 4;
    constexpr int ARR_SIZE2 = 7;

    int arr[ARR_SIZE] = {9, 5, 66, 77};
    int arr2[ARR_SIZE2] = {63, 252, 3, 3, 2, 3, 166};
    // doubly linked list
    std::list<int> l;
    l.push_back(2);
    l.push_front(1);
    // l.pop_back();
    // l.pop_front();
    auto x = l.front();
    auto y = l.back();

    l.insert(l.begin(), arr, arr + ARR_SIZE);
    l.insert(l.begin(), arr2, arr2 + ARR_SIZE2);
    l.insert(l.begin(), /*(# of occurences)*/ 5, 50);
    // l.insert() -> one by move, and one by const ref

    std::cout << "l.size()= " << l.size() << '\n';
    copy(l.begin(), l.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    l.remove_if([](int x)
                { return x == 3; });
    std::cout << "l.size()= " << l.size() << '\n';
    copy(l.begin(), l.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    // remove EVERY(value) exits in list, expect list of pointers.
    // l.remove()
    // remove range OR index based on Iterator.
    // l.erase()

    l.remove_if([](int x)
                { return x == 3; });
    // Sort is O(NlogN) --> merge sort
    l.sort(std::less<int>());
    copy(l.begin(), l.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    l.sort(std::greater<int>());
    copy(l.begin(), l.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    // l.merge();

    // Transfer elements from one list to another,
    // reassigns the internal pointers of each node to the new position without copying or moving the data
    list<int> l2(arr, arr + ARR_SIZE);
    // Transfare l2 to l
    l.splice(l.begin(), l2); // For whole list
    // l1.splice(l.begin(), l2, l2.begin()); // For single element
    // l1.splice(l.begin(), l2, l2.begin(), l2.end()); // For range of elements.
    // std::next(it, value):
    // An iterator of type InputIt that holds the nth successor (or -nth predecessor if n is negative) of iterator it.
    l.splice(l.begin(), l, next(l.begin(), 3),
             l.end());

    // Removes all duplicate consecutive elements from the list. It works only on sorted list.
    l.sort();
    l.unique();

    copy(l.begin(), l.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    // Assigns new elements to the list by
    // replacing current elements and resizing the list.
    l.assign(arr2, arr2 + 3);
    std::cout << "After use assign() l.size()= " << l.size() << '\n';
    copy(l.begin(), l.end(), std::ostream_iterator<int>(cout, " "));

    std::cout << std::endl;
    return 0;
}