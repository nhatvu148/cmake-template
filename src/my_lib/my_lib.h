#pragma once

#include <array>
#include <string_view>

void print_hello_world();

int add_numbers(int a, int b);

void say_age(const int &age);

double sum(double scores[], size_t count);

void say_my_name(std::string_view name);

// Templated code implementation should never be in a .cpp file:
// your compiler has to see them at the same time as it sees the code that calls them
template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b; // a and b must support the > operator
}

// Overload through templates. Will take precedence over raw T if a pointer is passed to maximum
template <typename T>
T *maximum(T *a, T *b)
{
    std::cout << "Template overload called (T*)" << std::endl;
    return (*a > *b) ? a : b;
}

template <typename ReturnType, typename T, typename P>
ReturnType maximum(T a, P b)
{
    return (a > b) ? a : b; // a and b must support the > operator
}

void print(auto view)
{
    for (auto i : view) // computation happens here
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}