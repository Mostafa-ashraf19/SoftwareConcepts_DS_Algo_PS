// s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c){ 
//             return !std::isalnum(c);
//              }), s.end());
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numOfConsecutiveChars(string s) {
    int count = 0, i=0;

    while(i < s.length() - 1) {
        if(s[i] == s[i+1]) {
            ++count;
            ++i;
        }
        ++i;
    }
    return count;
}

int getDiffAnagram(string a, string b) {

    std::vector<int> freq(26, 0);

    if(a.size() != b.size())
        return -1;
    int count = 0;
    for(const auto& c : a) {
        ++freq[c-'a'];
    }
    for(const auto& c : b) {
        --freq[c-'a'];
        if(freq[c-'a']<0) {
            ++count;
        }
    }
    return count;
}

bool isPalindrome(string s) {

    s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c){ 
        return !std::isalnum(c);
            }), s.end());
    
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){
        return tolower(c);
    });

    int l=0, r = s.length() - 1;
    for(int i = 0; i < s.length() / 2; ++i) {
        if(s[l++] != s[r--]) {
            return false;
        }
    }
    return true;
}

#include <iostream>
using namespace std;

template <typename T>
T maxxx(T x, T y)
{
    return (x > y)? x : y;
}
int main()
{
    // cout << maxxx(3, '7') << std::endl;
    cout << max(3.0, 7.0) << std::endl;
    // cout << max(3, 7.0) << std::endl;
    return 0;
}


// int main(int argc , char* argv[]) {
//     // string s = "21Was it a car or a cat I saw?12";

//     // auto endIt = std::remove_if(s.begin(), s.end(), [](unsigned char c){ 
//     //                 return (!std::isalnum(c)) || (c > '0' && c < '9');
//     //             });

//     // s.erase(endIt, s.end());
//     int *x = nullptr;
//     delete x;
//     delete x;

//     int* ptr = new int(5);
//     std::cout << *ptr << '\n';

//     delete ptr;
//     // delete ptr;// dangling pointer
//     // std::cout << *ptr << '\n'; // dangling pointer

//     ptr = nullptr;
//     ptr = nullptr;

//     // const char* s = argv[1];
//     // int * a = new int;
    

//     // std::cout << numOfConsecutiveChars(s) << '\n';

//     return 0;
// }

/*

#include<iostream>
using namespace std;
int main ()
{
       int cin;
       cin >> cin;
       cout << "cin" << cin;
       return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int add(int x) {
//     return ++x;
// }
// int x = 3;

// // class empty{};

// class A {
//     public:

//     virtual void print() final {
//         cout << "Hi A\n";
//     }
// };

// class B : public A {
//     public: 
//     void print() {
//         cout << "Hi B\n";
//     }
// };

// int main() {
//     // A* a;
//     // char* ptr = "Hello";
//     // char* ptr2[] = {"Hi", "ok", "bye"};

//     // int x= 10;

//     // cout << sizeof(empty) << '\n';
//     return 0;
// }


*/
