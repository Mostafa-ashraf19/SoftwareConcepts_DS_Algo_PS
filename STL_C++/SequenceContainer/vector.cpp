#include <bits/stdc++.h>
using namespace std;

// Capacity its + 50% of size, example size=100 capacity=150
int main(int argc, char **argv)
{

    int arr[7] = {1, 2, 3, 4, 5, 7, 9};

    std::vector<int> v(arr, arr + 7);
    std::vector<int> v2 = {1,3,6,5,6,7};
    std::vector<int> v3{1,3,6,5,6,7};
    std::vector<int> v4({1,3,6,5,6,7});

    v.insert(v.begin(), arr, arr + 7);
    v.insert(v.begin() +2 , {7, 9, 8, 6, 2, 42, 63});
    v.insert(v.begin(), 3, 88);
    v.insert(v.begin() + 3, 1996);

    // Rvalue reference initialization
    int &&x = 2000;
    v.insert(v.begin() + 4, std::move(x));
    std::cout << x << " " << sizeof(x) << '\n';

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << "\nv.size()= " << v.size() << '\n';
    v.erase(v.begin());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << "\nv.size()= " << v.size() << '\n';
    v.erase(v.begin(), v.begin() + 4);
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << "\nv.size()= " << v.size() << '\n';
    /*
        // Constant Iterator
        v.crbegin();
        v.crend();
        // Constant Iterator
        v.cbegin();
        v.cend();
        // Reverse Iterator
        v.rend();
        v.rbegin();
        // Iterator
        v.end();
        v.begin();
    */

    // If index not exits, error outboud
    v.at(6) = 10;

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << "\nv.size()= " << v.size() << '\n';
    std::copy(v2.begin(), v2.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;
    std::copy(v3.begin(), v3.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;
    std::copy(v4.begin(), v4.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    // for (auto it = v.begin(); it != v.end(); ++it)
    // {
    //     std::cout << *it << ' ';
    // }

    std::cout << std::endl;
    return 0;
}

/*


Got it! Based on the job description you provided, here are the key technical topics you should focus on:

1. C++ Fundamentals
Syntax & Semantics: You need a solid understanding of C++ syntax (loops, conditionals, functions, classes, etc.).
Pointers & Memory Management: Understanding pointers, references, dynamic memory (new, delete), smart pointers (e.g., std::unique_ptr, std::shared_ptr), and the RAII (Resource Acquisition Is Initialization) principle.
Copying and Moving: Know how copy constructors, copy assignment operators, and move semantics work, particularly the role of std::move.
Namespaces: Understand how namespaces work and when to use them.
2. Object-Oriented Programming (OOP) Principles
Encapsulation, Inheritance, Polymorphism, and Abstraction: Know the core principles of OOP and how to apply them in C++.
Access Specifiers: Understand public, private, and protected access control.
Constructors & Destructors: Understand the purpose of default, parameterized, and copy constructors, as well as destructors.
Virtual Functions and Inheritance: Be able to explain and use virtual functions, dynamic polymorphism, and the need for virtual destructors.
3. Design Patterns
Focus on common C++ design patterns:
Singleton: Understand the purpose and implementation of a Singleton.
Factory: Know how the Factory design pattern works.
Observer: Understand how it is used for event-driven programming.
Strategy and Command: These can be useful in game development, GUI applications, etc.
4. Standard Template Library (STL)
Containers: Be familiar with std::vector, std::list, std::deque, std::map, std::set, etc.
Algorithms: Understand common algorithms like std::sort, std::find, std::transform, etc.
Iterators: Understand the use of iterators with STL containers.
Function Objects and Lambdas: Be comfortable with using function objects and lambda functions.
Memory management with STL: Know how std::allocator works and how to use it.
5. WinAPI Basics
Basic Windows Programming: Know how to create a simple Windows application using the WinAPI (creating windows, handling messages, etc.).
Event Loop and Message Handling: Understand how message loops and message processing work in WinAPI.
Multithreading (in the context of WinAPI): Basic knowledge of creating threads using WinAPI (e.g., CreateThread, WaitForSingleObject, etc.).
6. Multithreading
Threading in C++: Be familiar with the C++11 threading model (std::thread, std::mutex, std::lock, std::atomic, etc.).
Synchronization: Know how to use mutexes, locks, and condition variables for thread synchronization.
Concurrency Issues: Be aware of race conditions, deadlocks, and how to avoid them.
7. CMake Basics
Basic CMake Commands: Understand CMakeLists.txt, add_executable(), add_library(), target_link_libraries(), etc.
Setting Compiler Options: Understand how to set different compiler flags for specific build configurations.
Cross-platform Build Configuration: Understand how CMake helps in building multiplatform C++ projects.
8. Cross-Platform Development
Multiplatform Development: Familiarity with writing portable C++ code across Windows, Linux, MacOS, etc.
Conditional Compilation: Use of preprocessor directives like #ifdef, #ifndef for platform-specific code.
Platform-Specific Libraries: Familiarity with common libraries that help with cross-platform development.
9. Additional Bonus Skills (Nice to Have)
Android Development: If you have any experience with Android NDK (Native Development Kit) or JNI (Java Native Interface), this could be a plus.
FreeRTOS: Knowing how to work with RTOS (Real-Time Operating Systems) like FreeRTOS could be a plus for embedded systems roles.
Suggested Questions You May Encounter:
General C++ Knowledge:

How does C++ differ from C? What are some advantages of using C++ over C?
Can you explain the difference between a pointer and a reference in C++?
What is the purpose of the const keyword in C++?
Object-Oriented Programming:

What is polymorphism in C++? How is it achieved?
Can you explain how a virtual destructor works and why it's important?
What is the rule of three/five in C++?
STL Usage:

How would you implement a queue using STL containers?
What’s the difference between std::vector and std::list? When would you use one over the other?
WinAPI:

How do you create a basic window using the WinAPI in C++?
What is the message loop in Windows programming, and why is it important?
Multithreading:

How would you implement a thread-safe data structure in C++?
Can you explain the difference between std::mutex and std::atomic? When would you use each?
CMake:

Can you explain how to structure a CMake project?
How would you configure CMake to work on multiple platforms?
Resources to Study:
C++ Basics & STL:

C++ Programming Language (Stroustrup) (Book)
Learn C++ (Website)
Object-Oriented Programming (OOP):

Design Patterns in C++ (Website)
Object-Oriented Design & Programming (Tutorial)
WinAPI:

Microsoft WinAPI Documentation
WinAPI Tutorial for Beginners
Multithreading in C++:

C++ Multithreading (Tutorial)
Multithreading with C++11 (GeeksforGeeks)
CMake:

CMake Documentation (Official Documentation)
CMake Tutorial (Tutorial)
Quick Tips for the Interview:
Be clear about your past projects: When discussing your experience, emphasize how you've used the core C++ concepts (like OOP and STL) in real-world projects.
Prepare to explain your design choices: If asked to design a system or explain an approach, focus on clean code, scalability, and efficiency.
Understand multithreading: Be ready to discuss thread safety, race conditions, and synchronization in C++.
Showcase problem-solving: If you're given coding problems, make sure to demonstrate efficient, scalable solutions.
Good luck with your interview! Let me know if you need any more help

*/