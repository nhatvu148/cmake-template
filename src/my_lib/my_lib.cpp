#include <iostream>

#include <nlohmann/json.hpp>

#include "my_lib.h"

void print_hello_world()
{
    std::cout << "Hello World!\n";

    std::cout << "JSON Lib Version:" << NLOHMANN_JSON_VERSION_MAJOR << "."
              << NLOHMANN_JSON_VERSION_MINOR << "."
              << NLOHMANN_JSON_VERSION_PATCH << "\n";
}

int add_numbers(int a, int b)
{
    return a + b;
}

void say_age(const int &age)
{
    std::cout << "You are " << age << " years old"
              << "\n";
}

// arrays passed to functions decay to pointers => cannot use std::size => should also pass size_t count
double sum(double scores[], size_t count)
// double sum(double *scores, size_t count)
{
    double score_sum{};

    // std::cout << "sizeof(scores)  : " << sizeof(scores) << std::endl;
    // std::cout << "sizeof(int*) : " << sizeof (int *) << std::endl;
    // size_t arr_size = std::size(scores);

    for (size_t i{0}; i < count; ++i)
    {
        score_sum += scores[i];
    }
    return score_sum;
}

void say_my_name(std::string_view name)
{
    std::cout << "Hello your name is : " << name << std::endl;
}

// a raw overload will take precedence over any template instance if const char * is passed to maximum
const char *maximum(const char *a, const char *b)
{
    std::cout << "Raw overload called" << std::endl;
    return (std::strcmp(a, b) > 0) ? a : b;
}

#ifdef _WIN32
/* Prints Contents of Memory Blocks */
void print_bytes(const void *object, size_t size)
{
    const unsigned char *const bytes = static_cast<const unsigned char *>(object);
    size_t i;

    printf("[-");
    for (i = 0; i < size; i++)
    {
        // printf(bytes[i]);
        int binary[8];
        for (int n = 0; n < 8; n++)
        {
            binary[7 - n] = (bytes[size - 1 - i] >> n) & 1;
        }
        /* print result */
        for (int n = 0; n < 8; n++)
        {
            printf("%d", binary[n]);
        }
        printf("%c", '-');
    }
    printf("]\n\n");
}

void print_text_to_file(const char *text, const char *filename)
{
    // Open the file for writing
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        perror("Error opening file");
        return;
    }

    fprintf(file, "Value is %s\n\n", text);

    // Close the file
    fclose(file);
}

void print_wchar_to_file(const wchar_t *text, const char *filename)
{
    // Open the file for writing in wide character mode
    FILE *file = _wfopen(L"output.txt", L"wt");
    if (!file)
    {
        perror("Error opening file");
        return;
    }

    fwprintf(file, L"Value is %ls\n\n", text);

    // Close the file
    fclose(file);
}
#endif