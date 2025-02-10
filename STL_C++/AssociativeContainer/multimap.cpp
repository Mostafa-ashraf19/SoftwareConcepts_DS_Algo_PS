#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Y>
std::ostream &operator<<(std::ostream &out, const multimap<T, Y> &mp)
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

    std::multimap<string, int> m_mp(arr, arr + ARR_SIZE);
    std::cout << m_mp;

    // m_mp["1000"] = 2;
    m_mp.insert({"2502", 36});
    m_mp.insert({"2502", 200});


    cout << m_mp.count("100") << '\n';
    cout << m_mp.count("2502") << '\n';

    // auto res = m_mp.find("1000");
    // cout << (*res).first << " " << (*res).second << '\n';

    std::cout << m_mp;

    std::cout << endl;

    return 0;
}