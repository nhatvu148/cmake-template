#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <ranges>
#include <map>

#include "my_lib.h"

namespace ranges = std::ranges;

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

    std::cout << "-----------------"
              << "\n";
    // Lambda function signature:
    // [capture list] (parameters) -> return type {
    // function body
    // }
    //
    // [=] capture everything by value
    // [&] capture everything by reference
    auto f = []()
    {
        std::cout << "Hello from lambda!!"
                  << "\n";
    };

    f();

    double aa{10};
    double bb{20};

    auto f1 = [aa, bb]()
    {
        std::cout << "aa + bb = " << aa + bb
                  << "\n";
    };

    f1();

    auto cc{42};
    auto f2 = [&cc]()
    {
        std::cout << "Inner value: " << cc << "\n";
    };

    for (size_t i{}; i < 5; ++i)
    {
        std::cout << "Outer value: " << cc << "\n";
        f2();
        ++cc;
    }

    std::cout << "-----------------"
              << "\n";

    std::cout << "Maximum1: " << maximum(12.5, 13.5) << "\n";
    std::cout << "Maximum2: " << maximum<int>(12, 13) << "\n";
    std::cout << "Maximum3: " << maximum("hello", "world") << "\n";

    int xx{100};
    int yy{200};
    std::cout << "Maximum4: " << *maximum(&xx, &yy) << "\n";
    std::cout << "Maximum5: " << maximum<double>(12, 123.345) << "\n";

    auto func = []<typename T, typename P>(T a, P b)
    {
        return a + b;
    };

    std::cout
        << "func: " << func(2, 3.9) << std::endl;

    std::cout << "-----------------"
              << "\n";
    std::vector<int> v{10, 2, 13, 20, 123, 77};

    auto DivisibleBy = [](int d)
    {
        return [d](int m)
        { return m % d == 0; };
    };

    if (ranges::any_of(v, DivisibleBy(7)))
        std::cout << "At least one number is divisible by 7\n";

    if (std::any_of(v.cbegin(), v.cend(), DivisibleBy(7)))
        std::cout << "At least one number is divisible by 7\n";

    ranges::for_each(v, [](int &n)
                     { n *= 2; });
    ranges::sort(v);
    std::cout << "Among the numbers: ";
    ranges::copy(v, std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    if (auto result = ranges::find_if(v, [](int x)
                                      { return x % 13 == 0; });
        result != v.end())
        std::cout << "First element divisible by 13 in v: " << *result << '\n';
    else
        std::cout << "No elements in v are divisible by 13\n";

    // a view is a non owning range
    // it's like a window we can set up to view some real data without setting up the infra to store data
    // views are cheap to copy and pass around as function parameters
    // auto v_evens = std::views::filter(v, [](int i)
    //                                   { return (i % 2) == 0; });
    ranges::filter_view v_evens = ranges::filter_view(v, [](int i)
                                                      { return (i % 2) == 0; }); // no computation
    std::cout << "v evens: ";
    print(v_evens);
    std::cout << "v odds: ";
    print(std::views::filter(v, [](int i)
                             { return (i % 2) != 0; }));

    ranges::take_view v_taken = std::views::take(v, 3); // or ranges::take_view(v, 3)
    std::cout << "v taken:";
    print(v_taken);

    ranges::take_while_view v_taken_while = std::views::take_while(v, [](int i)
                                                                   { return (i % 2) == 0; });
    std::cout << "v taken while:";
    print(v_taken_while);

    std::cout << "-----------------"
              << "\n";
    // Raw function composition:
    std::vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto even = [](int n)
    { return n % 2 == 0; };
    auto my_view = std::views::transform(std::views::filter(vi, even), [](auto n)
                                         { return n *= n; });
    std::cout << "vi transformed: ";
    print(my_view);

    // Pipe operator:
    auto my_view2 = vi | std::views::filter(even) | std::views::transform([](auto n)
                                                                          { return n *= n; });
    std::cout << "vi transformed: ";
    print(my_view2);

    // classroom done as map : Keys are sorted by default
    // std::unordered_map<std::string,unsigned int> classroom    {
    std::map<std::string, unsigned int> classroom{
        {"John", 11},
        {"Mary", 17},
        {"Steve", 15},
        {"Lucy", 14},
        {"Ariel", 12}};

    // Print out the names
    // auto names_view = std::views::keys(classroom);
    auto names_view = classroom | std::views::keys;
    std::cout << "names : ";
    std::ranges::copy(names_view, std::ostream_iterator<std::string>(std::cout, " "));

    // Print out the ages :
    std::cout << std::endl;
    // auto ages_view = std::views::values(classroom);
    auto ages_view = classroom | std::views::values;
    std::cout << "ages : ";
    std::ranges::copy(ages_view, std::ostream_iterator<unsigned int>(std::cout, " "));

    // Print names in reverse : this doesn't work if you store the data in an
    // unordered_map. The reason in the unoredered_map doesn't have reverse iterators,
    // that are needed to set up a reverse view.
    std::cout << std::endl;
    std::cout << "names in reverse : ";
    std::ranges::copy(std::views::keys(classroom) | std::views::reverse,
                      std::ostream_iterator<std::string>(std::cout, " "));

    // Pick names that come before the letter "M" in the alphabet
    std::cout << std::endl;
    auto before_M = [](const std::string &name)
    {
        return (static_cast<unsigned char>(name[0]) < static_cast<unsigned char>('M'));
    };

    std::cout << "names before M : ";
    std::ranges::copy(classroom | std::views::keys | std::views::filter(before_M),
                      std::ostream_iterator<std::string>(std::cout, " "));

    // https://en.cppreference.com/w/cpp/algorithm
    // https://en.cppreference.com/w/cpp/ranges

    // using range constructor
    for (int i : std::ranges::iota_view{1, 10})
        std::cout << i << ' ';
    std::cout << '\n';

    // using range adaptor
    for (int i : std::views::iota(1, 10))
        std::cout << i << ' ';
    std::cout << '\n';

    for (int i : std::views::iota(1) | std::views::take(9))
        std::cout << i << ' ';
    std::cout << '\n';

#ifdef _WIN32
// #if defined(__unix__) || defined(__linux__)
    std::cout << "-----------------"
              << "\n";

    std::cout << "\nStoring a Wide Char in Memory";
    std::cout << "\n------------------------\n\n";

    wchar_t pi = L'π';

    std::cout << "Address is " << static_cast<void *>(&pi) << "\n\n";
    std::cout << "Size is " << sizeof(pi) << " bytes\n\n";
    std::wcout << "Value is " << pi << "\n\n";

    std::cout << "\nMemory Blocks : \n";
    print_bytes(&pi, sizeof(pi));

    const char data123[] = "Hello, World!";
    print_text_to_file(data123, "output.txt");

    const wchar_t wdata[] = L"Hello, Wide World! π π π";
    print_wchar_to_file(wdata, "output.txt");
#endif

    return 0;
}
