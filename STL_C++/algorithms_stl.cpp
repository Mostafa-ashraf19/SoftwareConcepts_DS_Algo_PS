#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{

    int arr[7] = {1, 2, 3, 4, 5, 7, 9};
    std::vector<int> v(arr, arr + 7);

    std::vector<int>::const_iterator cit = std::min_element(v.begin(), v.end());
    std::cout << *cit << std::endl;

    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> pIt = std::minmax_element(v.begin(), v.end());
    std::cout << *pIt.first << " " << *pIt.second;
    
    // Move Semantics
    std::vector<int> v2 = {1, 6, 7, 8};
    std::cout << "Size of v2 before move: " << v2.size() << '\n';
    // Transfer ownership.
    std::vector<int> v3(std::move(v2));
    std::cout << "Size of v2 after move: " << v2.size() << '\n';


    std::cout << std::endl;
    return 0;
}
