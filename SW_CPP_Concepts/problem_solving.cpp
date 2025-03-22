#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include <string>

using namespace std;

unordered_map<char, string> mp = {{'2',{'a', 'b', 'c'}},
                                  {'3',{'d', 'e', 'f'}},
                                  {'4',{'g', 'h', 'i'}},
                                  {'5',{'j', 'k', 'l'}},
                                  {'6',{'m', 'n', 'o'}},
                                  {'7',{'p', 'q', 'r', 's'}},
                                  {'8',{'t', 'u', 'v'}},
                                  {'9',{'w', 'x', 'y', 'z'}}};

void backtrack(int index, std::vector<char>& tempList, string digits, std::vector<string>& results) {
    if(tempList.size() == digits.size()) {
        // Join
        results.push_back(std::string(tempList.begin(), tempList.end()));
        return;
    } else {
        for(auto& _charac : mp[digits[index]]) {
            tempList.push_back(_charac);
            backtrack(index + 1, tempList, digits, results) ;
            tempList.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits) {
    std::vector<string> results;
    std::vector<char> tempList;
    if(digits.length() == 0) 
        return  results;
    backtrack(0, tempList ,digits , results);
    return results;
}

int main() {
    auto results = letterCombinations("23");
    std::cout << results.size() << '\n';
    for(auto okk : results) {
        std::cout << okk << "  ";
    }
    std::cout << '\n';
    return 0;
}





// unordered_map<char, string> mp = {
//         {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
//         {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
//         {'8', "tuv"}, {'9', "wxyz"}
//     };