#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    
    constexpr int ARR_SIZE = 4;
    int arr[ARR_SIZE] = {9, 5, 66, 77};

    // singly linked list
    forward_list<int> fl;
    
    fl.push_front(20);

    fl.insert_after(fl.before_begin(), 100);

    fl.insert_after(fl.begin(), {30,26,2,5,6,4,6});
    fl.insert_after(next(fl.begin(), 3), 3);

    fl.insert_after(next(fl.begin(), 4), arr, arr + ARR_SIZE);

    fl.insert_after(next(fl.begin(), 2), 5, 20);
    copy(fl.begin(), fl.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << '\n';

    fl.assign(arr, arr+ARR_SIZE);
    copy(fl.begin(), fl.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << '\n';

    return 0;
}