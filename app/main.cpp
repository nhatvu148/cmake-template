#include <iostream>
#include <ctime>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <array>
#include <iterator>

#include "my_lib.h"

// Marking a function as constexpr gives it the potential
// to be evaluated at compile time
constexpr int get_value(int multiplier)
{
    return 3 * multiplier;
}

// Evaluate this function at compile time. If you can't
// do that throw a compiler error
consteval int get_value1(int multiplier)
{
    return 3 * multiplier;
}

constinit int some_var = 12345;

int main(int argc, char **argv)
{
    // srand() has to run once per program run
    std::srand(std::time(0)); // Seed

    std::cout << "Hello there"
              << "\n";
    std::cout << "number of args: " << argc << "\n";

    for (int i = 0; i < argc; ++i)
    {
        std::cout << "Argument " << i << ": " << argv[i] << "\n";
    }

    std::cout << "Sum is " << add_numbers(1, 2) << "\n";

    // looks dangerous here when reassigning
    // evaluate at compile time
    constexpr auto my_var = 23u;
    // my_var = -12;

    // check at compile time
    static_assert(my_var == 23);

    some_var = 1211;
    std::cout << "some_var is " << some_var << "\n";
    std::cout << "my_var is " << my_var << "\n";

    const auto x = 1;
    const auto y = x << 3; // Equivalent to multiplying x by 2^3
    std::cout << "result is " << y << "\n";

    // size_t is alias for unsigned int
    // unsigned int a{};

    // range based for loop with initializer
    for (double multiplier{4}; auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9})
    {
        std::cout << "res: " << (i * multiplier) << "\n";
    }

    int class_sizes[]{10, 12, 15, 17, 19, 20};
    // std::size(class_sizes)
    // or: size_t count { sizeof(class_sizes) / sizeof(class_sizes[0]) };

    for (auto value : class_sizes)
    {
        std::cout << "value: " << value << "\n";
    }

    std::cout << "-----------------"
              << "\n";

    // not good
    // char message[5]{'H', 'e', 'l', 'l', 'o'};
    // good
    char message[6]{'H', 'e', 'l', 'l', 'o', '\0'};
    message[0] = 'B'; // can do

    std::cout << message << std::endl;
    std::cout << std::size(message) << std::endl;

    // a literal C string - a char array with a null terminated string, an implicit '\0' character is appended making it a C string
    char message1[]{"Hello"};

    std::cout << message1 << std::endl;
    std::cout << std::size(message1) << std::endl;

    char numbers[]{1, 2, 3, 4};
    // bad!!
    // numbers[1000] = 10;
    // std::cout << numbers << std::endl;

    std::cout << "-----------------"
              << "\n";

    // string literal is made up of const char
    const char *p_message{"Hello World!"};
    // bad!!
    // *p_message = 'B';

    std::cout << p_message << std::endl;
    std::cout << *p_message << std::endl;

    const char *p_messages[]{
        "a lot of kids running in the backyard!",
        "a lot of empty beer bootles on your work table.",
        "you Partying too much with kids wearing weird clothes.",
        "you running away from something really scary",
        "clouds gathering in the sky and an army standing ready for war",
        "dogs running around in a deserted empty city",
        "a lot of cars stuck in a terrible traffic jam",
        "you sitting in the dark typing lots of lines of code on your dirty computer",
        "you yelling at your boss. And oh no! You get fired!",
        "you laughing your lungs out. I've never seen this before."};

    size_t rand_num = static_cast<size_t>((std::rand() % std::size(p_messages)));
    std::cout << p_messages[rand_num] << std::endl;

    std::cout << "-----------------"
              << "\n";
    // Pointer is constant (can't make it point anywere else)
    // but pointed to value can change
    std::cout << "Pointer is contant, pointed to value can change : " << std::endl;
    int number7{982};

    int *const p_number7{&number7};

    std::cout << "p_number7 :" << p_number7 << std::endl;
    std::cout << "*p_number7 : " << *p_number7 << std::endl;
    std::cout << "Changing value pointed to through p_number7 pointer : " << std::endl;

    *p_number7 = 456;
    // p_number7 = &number8; // bad!!
    std::cout << "The value pointed to by p_number7 now is : " << *p_number7 << std::endl;

    for (const char *message : p_messages)
    {
        std::cout << message << "\n";
    }

    // bad!!
    // *p_messages[0] = 'K';
    const char *new_message{"good day, good future"};
    p_messages[0] = new_message;

    std::cout << "-----------------"
              << "\n";
    int arr0[5]{1, 2, 3, 4, 5};
    int arr1[5]{6, 7, 8, 9, 10};
    int *p_arr1{arr1};
    int *p_arr0{arr0};

    // swap arrays
    int *temp{nullptr};

    temp = p_arr1;
    p_arr1 = p_arr0;
    p_arr0 = temp;

    // Print arr0
    std::cout << "arr0 : ";
    for (size_t i{}; i < std::size(arr0); ++i)
    {
        std::cout << p_arr0[i] << " ";
    }
    std::cout << std::endl;

    // Print arr1
    std::cout << "arr1 : ";
    for (size_t i{}; i < std::size(arr1); ++i)
    {
        std::cout << p_arr1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "-----------------"
              << "\n";

    // int *p_number{}; // or int *p_number;
    // bad!!
    // *p_number = 10;

    int *p_number1{nullptr};
    p_number1 = new int; // dynamically allocate space for a single int on the heap
    *p_number1 = 10;     // writing into dynamically allocated memory
    // int * p_number1 { new int {23} }

    if (p_number1 != nullptr)
    {
        std::cout << "Dynamically allocated memory: " << *p_number1 << "\n";
    }

    delete p_number1;    // release memory and return it to system
    p_number1 = nullptr; // reset it to nullptr for safety

    std::cout << "-----------------"
              << "\n";
    int *p_number2{new int{123}};
    // use pointer here
    // should delete and reset here

    int number{100};
    // bad!! memory leak!
    // p_number2 = &number;
    // p_number2 = new int{222};

    std::cout << "-----------------"
              << "\n";

    // crazy memory leak
    // int * p_crazy{};
    // while (true) {
    //     p_crazy = new int {};
    // }

    // references behave like constant pointers, but don't require dereferencing to read and write
    double double_value{1.0};
    double *const const_p_double_value{&double_value};

    double &ref_double_value{double_value};

    std::cout << "-----------------"
              << "\n";

    int scores[]{1, 2, 3, 2, 3, 4, 5, 6};
    for (auto &score : scores)
    {
        score = score * 10;
    }

    std::cout << "Scores: ";
    for (auto score : scores)
    {
        std::cout << " " << score;
    }
    std::cout << std::endl;

    std::cout << "-----------------"
              << "\n";
    std::string planet{"Earth. Where the sky is blue"}; // Initialize with string literal
    // Changing std::string at runtime
    planet = "Earth. Where the sky is blue Earth. Where the sky is blue Earth.";
    std::cout << "planet : " << planet << std::endl;

    // Use a raw array, will be wasted if reassigned a new value
    const char *planet1{"Earth. Where the sky is blue Earth."};
    planet1 = "Earth. Where the sky is blue Earth. Where the sky is blue Earth.";
    std::cout << "planet1 : " << planet1 << std::endl;

    std::string str{"Hello World"};
    char *data = str.data();
    std::cout << "Wrapped C string: " << data << std::endl;
    data[0] = 'B'; // This also changes std::string

    std::cout << "Wrapped C string (after modification): " << data << std::endl;
    std::cout << "Original string (after modification): " << str << std::endl;
    // https://cplusplus.com/reference/string/string/c_str/
    // https://stackoverflow.com/questions/4764897/converting-a-c-style-string-to-a-c-stdstring

    std::cout << "-----------------"
              << "\n";

    std::string_view sv{"Hello"};
    std::string_view sv1{sv};  // View viewing the hello literal, save memory
    std::string_view sv2{sv1}; // another View viewing the hello literal

    std::cout << "sv: " << sv << std::endl;
    std::cout << "sv1: " << sv1 << std::endl;
    std::cout << "sv2: " << sv2 << std::endl;

    std::cout << "-----------------"
              << "\n";

    say_age(100);

    double my_scores[]{10.5, 34.3, 4.8, 6.5};
    double result = sum(my_scores, std::size(my_scores));
    std::cout << "result : " << result << std::endl;
    // std::string some_name{"John"};
    // say_my_name("John");
    say_my_name(std::string_view("Anthony"));

    std::cout << "-----------------"
              << "\n";
    /*
        For the evaluation to take place at compile time, we have
        to remember to store the return value in a constexpr result variable
    */
    constexpr int result1 = get_value(4); // Compile time
    std::cout << "result : " << result1 << std::endl;

    /*
    int some_var{5}; // Run time variable
    int result2 = get_value(some_var); // Run time
    std::cout << "result : " << result2 << std::endl;
    */

    int result2 = get_value1(4);

    // the value of some_var is not known at compile time
    // int some_var{5};
    // result2 = get_value1(some_var);

    std::array<int, 6> a{{0, 1, 2, 3, 4, 5}};
    boost::random_shuffle(a);
    boost::copy(a, std::ostream_iterator<int>{std::cout, ","});
    std::cout << "\n"
              << *boost::max_element(a) << '\n';
    std::cout << boost::accumulate(a, 0) << '\n';

    return 0;
}
