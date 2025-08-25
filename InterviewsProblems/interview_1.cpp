/*


The issue with your code lies in how you're modifying the std::list while iterating through it.
Specifically, the problem is that you're erasing elements from the list while still using the iterator to traverse it.
This can lead to undefined behavior, because after an element is erased, the iterator becomes invalid.

The issue in detail:
Erasing while iterating: When you erase an element from the list, the iterator i pointing to that element is invalidated.
After erasing an element, the iterator i no longer points to a valid position, and continuing to use it leads to undefined behavior.

Iterator invalidation: In std::list, erasing an element shifts the list, and the iterator i becomes invalid.
You cannot simply continue using the iterator after erasing an element from the list.

Solution:
You need to handle the iterator properly when you erase an element.
One way to do this is to get the iterator to the next element before erasing the current element.
std::list::erase returns an iterator pointing to the element following the one that was erased, which can be used in the next iteration.

Corrected Code:

#include <iostream>
#include <list>

typedef std::list<int> _list;

extern bool bad(int);

int main() {

    _list l;

    for (_list::iterator i = l.begin(); i != l.end(); )  // Notice the different loop condition
    {
        if (bad(*i)) {
            i = l.erase(i);  // erase returns the iterator to the next element
        } else {
            ++i;  // only increment the iterator if no erase happened
        }
    }

    return 0;
}
Explanation of Changes:
Iterator Handling:
The iterator is updated in two ways:
If bad(*i) is true (i.e., the current element should be erased), i = l.erase(i) is called.
This erases the current element and updates i to point to the next element (the iterator returned by erase).

If the element is not erased, the iterator is simply incremented (++i) to move to the next element.

Iterator Invalidation Avoided:
This approach ensures that the iterator i is always valid, because you either move to the next element after erasing,
or you increment it normally when no element is erased.

Conclusion:
The key change is to update the iterator properly when erasing an element from the list.
Always ensure that after an erase operation, you use the iterator returned by erase, which points to the element after the one that was just removed.

typedef std::list<int> _list;

extern bool bad(int);

int main() {

    _list l;

    for (_list::iterator i = l.begin(); i != l.end(); i++)
    {
        if(bad(*i))
            l.erase(i);
    }

    return 0;

}

*/

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class A
{
protected:
    virtual void print();
};

class B
{
};

enum SOL_TYPE
{
    SUFFIX_SOLUTION = 0,
    PREFIX_SOLUTION
};

// find max diff between two nums, (large number) appears AFTER (smaller number).
int maxDifference(const std::vector<int> &nums, const SOL_TYPE &sol_type)
{
    // {1000, 2, 3, 10, 6, 4, 8, 1} -> (2,10) = 10
    int ans = INT_MIN;
    if (sol_type == SUFFIX_SOLUTION)
    {
        // Suffix solution
        int maxDiff_so_far = nums.back();
        for (int i = static_cast<int>(nums.size() - 2); i >= 0; --i)
        {
            if (nums[i] < maxDiff_so_far)
            {
                ans = std::max(ans, maxDiff_so_far - nums[i]);
            }
            maxDiff_so_far = std::max(maxDiff_so_far, nums[i]);
        }
    }
    else
    {
        // Prefix solution
        int min = nums.front();
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                ans = std::max(ans, nums[i + 1] - min);
            }
            min = std::min(min, nums[i]);
        }
    }
    return ans;
}

std::vector<int> prefixSum(const std::vector<int> &arr)
{

    std::vector<int> v(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
            {v[i] = arr[i];}
        else
            {v[i] = v[i-1] + arr[i];}
    }
    return v;
    // return std::move(v);
}

int range_sum(const std::vector<int> &nums, const int &start, const int &end)
{
    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum += nums[i];
    }
    return sum;
}

// int subArraySum(const std::vector<int> &arr, const int &k)
// {
//     // int counter = 0;
//     // if(nums.back() == k)
//     //     ++counter;
//     // for (int i = 0; i < nums.size() - 1; i++)
//     // {
//     //     if (nums[i] == k || (nums[i] + nums[i + 1] == k))
//     //         ++counter;
//     // }
//     // return counter;
//     // int res = 0;
//     // // {1, 1, 1} 2 
//     // // {1, 2, 3} 3
//     // // {2, 5, 15, 6, 4, -24} 8 
//     // auto prefixSumRes = prefixSum(nums);
//     // for (const auto &v : prefixSumRes)
//     //     std::cout << v << " ";
//     // std::cout << std::endl;
//     // // {1, 2, 3} 
//     // // {1, 3, 6}
//     // // {2, 7, 22, 28, 32, 8}

//     // for (int start = 0; start < prefixSumRes.size(); start++)
//     // {
//     //     for (int end = start; end < prefixSumRes.size(); end++)
//     //     {
//     //         if (range_sum(prefixSumRes, start, end) == k)
//     //             ++res;
//     //     }
//     // }
//     // return res;
// for (int i = 0; i < arr.size(); i++)
// {
//     for (int j = 0; j < arr.size(); j++)
//     {
//         cout << arr[i][j] << '\n';
//     }   
// }

// for (int i = 0; i < arr.size(); i++)
// {
//     for (int j = 0; j < arr.size(); j++)
//     {
//         cout << arr[j][i] << '\n';
//     }   
// }

//     int res = 0, prefix_sum = 0;
//     unordered_map<int, int> htable;
//     htable[0] = 1;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         // Cummlative sum
//         prefix_sum += nums[i];
//         if(htable.count(prefix_sum - k))
//             res += htable[prefix_sum - k];
//         ++htable[prefix_sum];
//     }
//     return res;
    
// }

void printRevString(const string& str, int idx) {
    if(str[idx]== '\0')
        return;
    printRevString(str, idx + 1);
    std::cout << str[idx] << ' ';
}

int main()
{
    
    printRevString("Mostafa", 0);
    std::cout << '\n';
    // std::cout << subArraySum({1, 1, 1}, 2) << '\n';
    // std::cout << subArraySum({1, 2, 3}, 3) << '\n';
    // std::cout << subArraySum({2, 5, 15, 6, 4, -24}, 8) << '\n';

    // std::cout << maxDifference({1000, 2, 3, 10, 6, 4, 8, 1}, SUFFIX_SOLUTION) << '\n';
    // std::cout << maxDifference({7, 9, 5, 6, 3, 2}, PREFIX_SOLUTION) << '\n';
    // std::cout << maxDifference({2, 5, 15, 6, 4}, PREFIX_SOLUTION) << '\n';

    // std::cout << "Size of Class(A) Empty class(with Virtual functions): " << sizeof(A) << '\n';
    // std::cout << "Size of Class(B) Empty class(without Virtual functions): " << sizeof(B) << '\n';
}