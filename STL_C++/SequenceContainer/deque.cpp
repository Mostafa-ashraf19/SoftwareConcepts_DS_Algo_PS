#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::deque<T> &v)
{
    s.put('{');
    char comma[]{'\0', ' '};
    // Can be:
    // for (/*C++23*/char comma[]{'\0', ' '}; const auto &e : v)
    // s << comma << e, comma[0] = ',';

    for (const auto &e : v)
    {
        s << comma << e;
        comma[0] = ',';
    }
    return s << "}\n";
}

// Custom Allocator that tracks allocations and deallocations
template <typename T>
struct MyAllocator
{
    using value_type = T;

    MyAllocator() = default;

    template <typename U>
    MyAllocator(const MyAllocator<U> &) {}

    T *allocate(std::size_t n)
    {
        std::cout << "Allocating " << n << " elements\n";
        return static_cast<T *>(::operator new(n * sizeof(T)));
    }

    void deallocate(T *p, std::size_t n)
    {
        std::cout << "Deallocating " << n << " elements\n";
        ::operator delete(p);
    }

    template <typename U>
    struct rebind
    {
        using other = MyAllocator<U>;
    };
};

int main(int argc, char **argv)
{

    // Allocator is lowlevel mechanism used for memory management
    // It defines how memory is allocated, deallocated, and handled for objects in container
    // (std::allocator), which simply allocates memory using the new and delete operators.
    // Can use custom allocator.
    std::deque<int> dq;

    dq.push_back(2); // one by move, and one by const ref
    dq.push_back(5);
    dq.push_back(26);

    dq.push_front(30); // one by move, and one by const ref

    int arr[7] = {1, 2, 3, 4, 5, 7, 9};

    dq.insert(dq.begin() + 3, arr, arr + 7);
    dq.insert(dq.begin(), /*(# of occurences)*/ 5, 50);
    dq.insert(dq.end(), {5, 9, 12});
    // dq.insert() -> one by move, and one by const ref

    // dq.erase() -> remove range OR value at specific place

    auto _allocator = dq.get_allocator();
    cout << _allocator.address(2600) << '\n';

    std::cout << "1: " << dq;

    std::cout << "dq.size()= " << dq.size();

    std::cout << std::endl;
    return 0;
}