#include <iostream>
#include <string>

using namespace std;
class Cat {

    public:

    string name;
    string type;
    int id;

    public:

    Cat(): id{0} {
    }

    Cat& SetName(string _name) {
        name = _name;
        return *this;
    }
    Cat& SetType(string _type) {
        type = _type;
        return *this;
    }
};


int main() {

    // Cat * c  = new Cat().SetName("Bosy").SetType("Girl");
    // int a[4] = {4, 8,10, 12};

    // int *ptr = a;
    int z = 3;
    int* y = &z;
    static const void* x =  z + 3; //y + 3;

    std::cout << *static_cast<int*>(x);
    // cout << ++*++ptr  << '\n';
    // cout <<   << '\n';

    // cout << c->name << " " << c->type << '\n';
    // float x = 3.2;
    // double y = 3.2;

    // if(x==y) {
    //     cout << "Hi\n";
    // } else {
    //     cout << "OKKK\n";
    // }

    return 0;
}