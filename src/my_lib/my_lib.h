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