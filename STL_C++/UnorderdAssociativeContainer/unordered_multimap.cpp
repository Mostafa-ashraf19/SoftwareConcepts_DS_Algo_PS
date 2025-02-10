#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Y>
std::ostream &operator<<(std::ostream &out, const unordered_multimap<T, Y> &mp)
{
    out.put('{');
    char comma[]{',', ' '};

    bool first = true;
    for (const auto &val : mp)
    {
        if (!first)
        {
            out << comma;
        }
        first = false;

        out.put('{');
        out << val.first << ',' << val.second;
        out.put('}');
    }
    return out << "}\n";
}

int main(int argc, char **argv)
{

    constexpr int ARR_SIZE = 12;
    pair<string, int> arr[ARR_SIZE] = {{"1", 9}, {"2", 5}, {"3", 66}, {"4", 77}, {"5", 1}, {"6", 12}, {"7", 16}, {"8", 28}, {"9", 100}, {"10", 152}, {"11", 120}, {"12", 152}};

    std::unordered_multimap<string, int> mp(arr, arr + ARR_SIZE);
    std::cout << mp;

    // mp["1000"] = 2; not exists
    mp.insert({"2502", 36});
    mp.insert({"2502", 36});
    mp.insert({"2502", 200});

    cout << mp.count("100") << '\n';
    cout << mp.count("2502") << '\n';

    auto res = mp.find("1");
    cout << (*res).first << " " << (*res).second << '\n';

    //  not exists
    // auto r = mp.at("1000");
    // cout << r << '\n';

    std::cout << mp;

    std::cout << endl;

    return 0;
}