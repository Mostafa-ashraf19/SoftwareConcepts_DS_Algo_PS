#include <iostream>
#include <string>

using namespace std;

class Singleton {
    
    static Singleton* uniqueInstance;
    std::string s;
    Singleton(std::string v) : s{v} {}

    void operator=(const Singleton &) = delete;
    Singleton(const Singleton &) = delete;

    public: 

    static Singleton& getInstance(std::string value) {
        if(uniqueInstance == nullptr) {
            uniqueInstance =  new Singleton(value);
        }
        return *uniqueInstance;
    }

    std::string getValue() const {
        return s;
    }

};

Singleton* Singleton::uniqueInstance = nullptr;

int main() {

    Singleton& s = Singleton::getInstance("Hello");
    std::cout << s.getValue() << '\n';
    Singleton& a = Singleton::getInstance("Hi");
    
    std::cout << s.getValue() << '\n';
    std::cout << a.getValue() << '\n';

    return 0;
}