#include <bits/stdc++.h>
using namespace std;

template <typename T>
class extendedVector : public std::vector<T>
{
public:
    // To enable inheritance.
    using std::vector<T>::vector;

    void right_rotate();
    void left_rotate();
    void right_rotate(int times);
    void left_rotate(int times);
    int pop(const int &idx);
    int find_transposition(const int &val);

    void print();

private:
};

template <typename T>
void extendedVector<T>::print()
{
    for (const auto &elem : *this)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void extendedVector<T>::right_rotate()
{
    T lastVal = this->back();

    for (int i = this->size() - 1; i > 0; --i)
    {
        this->operator[](i) = this->operator[](i - 1);
    }

    this->operator[](0) = lastVal;
}

template <typename T>
void extendedVector<T>::left_rotate()
{
    T frontVal = this->front();
    for (int i = 0; i < this->size() - 1; ++i)
    {
        this->operator[](i) = this->operator[](i + 1);
    }

    this->operator[](this->size() - 1) = frontVal;
}

template <typename T>
void extendedVector<T>::right_rotate(int times)
{
    if (times == 0)
        return;

    right_rotate();
    right_rotate(times - 1);
}

template <typename T>
void extendedVector<T>::left_rotate(int times)
{
    if (times == 0)
        return;

    left_rotate();
    left_rotate(times - 1);
}

// TODO
template <typename T>
int extendedVector<T>::pop(const int &idx)
{
    return 0;
}

// TODO
template <typename T>
int extendedVector<T>::find_transposition(const int &val)
{
    return 0;
}

// Capacity its + 50% of size, example size=100 capacity=150
int main(int argc, char **argv)
{

    extendedVector<int> extV = {1, 2, 3, 4, 5, 7, 9};
    extV.right_rotate(2);
    extV.print();
    // extV.left_rotate();
    // extV.print();

    std::cout << "-----------------------------------------\n";
    int arr[7] = {1, 2, 3, 4, 5, 7, 9};

    std::vector<int> v(arr, arr + 7);
    std::vector<int> v2 = {1, 3, 6, 5, 6, 7};
    std::vector<int> v3{1, 3, 6, 5, 6, 7};
    std::vector<int> v4({1, 3, 6, 5, 6, 7});

    v.push_back(6);

    v.insert(v.begin(), arr, arr + 7);
    v.insert(v.begin() + 2, {7, 9, 8, 6, 2, 42, 63});
    v.insert(v.begin(), 3, 88);
    v.insert(v.begin() + 3, 1996);

    // Rvalue reference initialization
    int &&x = 2000;
    v.insert(v.begin() + 4, std::move(x));
    std::cout << x << " " << sizeof(x) << '\n';

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << "\nv.size()= " << v.size() << '\n';
    v.erase(v.begin());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << "\nv.size()= " << v.size() << '\n';
    v.erase(v.begin(), v.begin() + 4);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << "\nv.size()= " << v.size() << '\n';
    /*
        // Constant Iterator
        v.crbegin();
        v.crend();
        // Constant Iterator
        v.cbegin();
        v.cend();
        // Reverse Iterator
        v.rend();
        v.rbegin();
        // Iterator
        v.end();
        v.begin();
    */

    // If index not exits, error outboud
    v.at(6) = 10;

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << "\nv.size()= " << v.size() << '\n';
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;
    std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;
    std::copy(v4.begin(), v4.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    // for (auto it = v.begin(); it != v.end(); ++it)
    // {
    //     std::cout << *it << ' ';
    // }

    std::cout << std::endl;
    return 0;
}
