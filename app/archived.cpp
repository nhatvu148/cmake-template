#include <iostream>
#include <ctime>

int add_numbers(int a, int b)
{
    return a + b;
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

    return 0;
}
