#include <bits/stdc++.h>
using namespace std;

enum SolType
{
    NAIVE = 0,
    BEST,
    BEST_2
};

// Arrays & Strings

// Two Sum – Given an array, find if two numbers sum to a target. (Hash map / two pointers)
vector<int> twoSum(vector<int> &nums, int target)
{
    std::map<int, int> rec;

    int idx = 0;
    for (auto num : nums)
    {
        auto diff = target - num;
        if (rec.find(diff) != rec.end())
        {
            return {rec[diff], idx};
        }
        else
        {
            rec[num] = idx;
        }
        idx++;
    }
    return {0, 0};
}

// Kadane’s Algorithm – Maximum subarray sum (dynamic programming).
// Max subarray naive solution o(n^2)
int maxSubArraySum(vector<int> &arr, const SolType &sol)
{
    if (sol == NAIVE)
    {

        int res = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            int currSum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                currSum = currSum + arr[j];

                res = std::max(res, currSum);
            }
        }
        return 0;
    }
    else
    {

        int res = arr[0];
        int maxEnd = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            maxEnd = max(maxEnd + arr[i], arr[i]);

            res = max(res, maxEnd);
        }

        return res;
    }
}

vector<int> maxSubArray(vector<int> &arr, const SolType &sol)
{
    int left, right;

    if (sol == NAIVE)
    {
        int res = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            int currSum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                currSum = currSum + arr[j];
                if (currSum > res)
                {
                    left = i;
                    right = j;
                    res = currSum;
                }
            }
        }
    }
    else
    {

        int res = arr[0];
        int maxEnd = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {

            if (maxEnd + arr[i] > arr[i])
            {
                maxEnd = maxEnd + arr[i];
            }
            else
            {
                right = i;
                maxEnd = maxEnd + arr[i];
            }

            if (maxEnd > res)
            {
                res = maxEnd;

                left = right;
                right = i;
            }
        }
    }

    std::vector<int> res;
    for (int i = left; i <= right; i++)
    {
        res.push_back(arr[i]);
    }
    return res;
}

// Rotate Array – Rotate by k positions (reverse trick).
void rotate(vector<int> &nums, int k)
{

    // std::rotate(nums.begin(), nums.end() - k, nums.end());
    k = k % nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// Dutch National Flag Problem – Sort 0s, 1s, and 2s.

// Sliding Window Maximum – Find max in each sliding window of size k.

// Longest Substring Without Repeating Characters – Hash set + sliding window.
int longestSubStr(string s, SolType sol)
{
/*

    // Generic solution

    int lengthOfLongestSubstring(string s)
    {

        if (s.length() <= 1)
            return s.length();
        unordered_map<char, int> arr;

        int l = 0, res = 0;
        for (int r = 0; r < s.length(); ++r)
        {
            if (arr.find(s[r]) != arr.end())
                l = max(l, arr[s[r]] + 1);

            arr[s[r]] = r;

            res = max(res, (r - l + 1));
        }

        return res;
    }
*/
    if (sol == NAIVE)
    {
        int res = 0;
        // o(26*n)
        for (int i = 0; i < s.length(); i++)
        {
            std::vector<bool> vis(26, false);
            for (int j = i; j < s.length(); j++)
            {
                if (vis[s[j] - 'a'] == false)
                {
                    vis[s[j] - 'a'] = true;
                    res = max(res, (j - i + 1));
                }
                else
                {
                    break;
                }
            }
        }
        return res;
    }
    else if (sol == BEST)
    {
        std::vector<int> last_seen(26, -1);
        std::vector<bool> vis(26, false);

        int l = -1, r = 0;
        int res = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (vis[s[i] - 'a'] == true)
            {
                l = i + 1;
            }
            else
            {
                vis[s[i] - 'a'] = true;
            }
            res = max(res, r - l + 1);
            ++r;
        }

        // cout << l << "   " << r << '\n';
        return res;
    }
    else
    {
        // By use Last Index of Each Character
        int l = 0;
        int res = 0;
        for (int r = 0; r < s.length(); r++)
        {

            // Can be
            // l = max(l, arr[s[r] - 'a'] + 1);
            if (last_seen[s[r] - 'a'] >= l)
            {
                l = last_seen[s[r] - 'a'] + 1;
            }

            last_seen[s[r] - 'a'] = r;

            res = max(res, r - l + 1);
        }

        return res;
    }
}

// Anagram Check – Compare two strings using frequency maps.
bool isAnagram(string s, string t) {
    if(s.length() != t.length())
        return false;
    
    vector<int> freq(26, 0);
    
    for(auto c: s)
        ++freq[c - 'a'];
    
    for(auto c: t)
        --freq[c - 'a'];
    
    return accumulate(freq.begin(), freq.end(), 0) == 0;
}

// String Reversal & Palindrome – Classic interview warm-ups.

int main()
{

    cout << longestSubStr("pwwkew", BEST) << '\n';
    // std::vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    // std::vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};

    // std::cout << maxSubArray(arr, BEST) << '\n';
    // auto res = maxSubArray(arr, BEST);

    // for (auto v : res)
    // {
    //     cout << v << ' ';
    // }

    cout << '\n';

    return 0;
}