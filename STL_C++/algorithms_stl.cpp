#include <bits/stdc++.h>
using namespace std;

// Important STL algorithms, most common used.

template <typename T>
std::ostream &operator<<(std::ostream &out, const vector<T> &v)
{
    for (const auto &i : v)
    {
        out << i << ' ';
    }
    return out << '\n';
}

int main(int argc, char **argv)
{

    int arr[7] = {1, 2, 3, 4, 5, 7, 9};
    std::vector<int> v(arr, arr + 7);
    std::vector<int> v2;

    copy(v.begin(), v.end(), back_inserter(v2));
    fill(v.begin(), v.end(), 3);

    cout << v << v2;
    std::vector<int> v3;
    transform(v.begin(), v.end(), back_inserter(v3), [](int x)
              { return x + 6; });
    std::cout << "After transform()" << v3;
    transform(v.begin(), v.end(), v.begin(), back_inserter(v3), std::logical_or<int>());
    std::cout << "After transform()" << v3;
    replace(v3.begin(), v3.end(), 1, 3);
    // Copy to new container with replace.
    // replace_copy()
    // replace_if() replace_copy_if()
    std::cout << "After replace()" << v3;

    // sort(v3.begin(), v3.end());

    vector<int> v4{1, 1, 1, 1, 1, 1, 5, 3, 2, 2, 2, 2, 36, 3, 4, 3, 2, 3, 3, 99, 12, 26};
    std::cout << "Before unique() " << v4;
    auto it_of_last_seq = unique(v4.begin(), v4.end());
    v4.resize(distance(v4.begin(), it_of_last_seq));
    std::cout << "After unique() " << v4;

    std::cout << endl;
    vector<int> v5{1, 1, 1, 1, 1, 1, 5, 3, 2, 2, 2, 2, 36, 3, 4, 3, 2, 2, 2, 4, 2, 3, 3, 99, 12, 26};
    std::cout << "Before unique() " << v5;
    // Here just remove consecutive TWOs
    it_of_last_seq = unique(v5.begin(), v5.end(), [](int x, int y)
                            {
        if(x == y /*&& x == 2*/){
            return true;
        }
        return false; });
    auto num_of_new_elements = distance(v5.begin(), it_of_last_seq);
    v5.resize(num_of_new_elements);
    std::cout << "After unique() " << v5;
    std::cout << "After unique() " << num_of_new_elements << '\n';

    // Get count of unique elements in array.
    vector<int> v6{1, 1, 1, 1, 1, 1, 5, 3, 2, 2, 2, 2, 36, 3, 4, 3, 2, 2, 2, 4, 2, 3, 3, 99, 12, 26};
    auto _2s_count = count(v6.begin(), v6.end(), 2);
    cout << "_2s_count= " << _2s_count << '\n';
    cout << "IS v6 sorted= " << is_sorted(v6.begin(), v6.end()) << '\n';
    sort(v6.begin(), v6.end());
    cout << "IS v6 sorted= " << is_sorted(v6.begin(), v6.end()) << '\n';
    it_of_last_seq = unique(v6.begin(), v6.end());
    auto num_of_uniques = distance(v6.begin(), it_of_last_seq);
    v6.resize(num_of_uniques);
    cout << "num_of_uniques= " << num_of_uniques << '\n';
    cout << v6;
    next_permutation(v6.begin(), v6.end());
    cout << v6;
    prev_permutation(v6.begin(), v6.end());
    cout << v6;

    std::vector<int>::const_iterator cit = std::min_element(v.begin(), v.end());
    std::cout << *cit << std::endl;

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> pIt = std::minmax_element(v.begin(), v.end());
    std::cout << *pIt.first << " " << *pIt.second << endl;

    // Move Semantics
    std::vector<int> v7 = {1, 6, 7, 8};
    std::cout << "Size of v7 before move: " << v7.size() << '\n';
    // Transfer ownership.
    std::vector<int> v8(std::move(v7));
    std::cout << "Size of v7 after move: " << v7.size() << '\n';

    std::cout << std::endl;
    return 0;
}
