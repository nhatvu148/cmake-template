#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void read_file();
void printString(std::string&& str);

// vector, list, stack, queue, dequeue, priority_queue, set, map, unordered_set, unordered_map
// vector: dynamic array
// list: doubly linked list
// stack: LIFO
// queue: FIFO
// dequeue: double-ended queue
// priority_queue: element with highest priority served first
// set: unique keys, sorted
// map: key-value pairs, sorted by key
// unordered_set: unique keys, unsorted
// unordered_map: key-value pairs, unsorted

class Move {
private:
    int *data;

public:
    Move(int d) : data(new int(d)) {}

    Move(const Move &source) : data(new int(*source.data)) {}

    Move(Move &&source) : data(source.data) {
        source.data = nullptr;
    }

    ~Move() {
        delete data;
    };

    // Getter for the data (since it's private)
    int getData() const { return *data; }
};

// Overload stream insertion operator
std::ostream& operator<<(std::ostream& os, const Move& move) {
    os << move.getData();
    return os;
}

int main() {
    // Create and open a text file
    ofstream MyFile("filename.txt");

    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";

    // Close the file
    MyFile.close();

    read_file();

    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    // Get the first element
    cout << cars.front();

    // Get the last element
    cout << cars.back();

    // Get the second element
    cout << cars.at(1);

    // Get the third element
    cout << cars.at(2);

    cars.push_back("Tesla");
    cars.push_back("VW");
    cars.push_back("Mitsubishi");
    cars.push_back("Mini");
    cars.pop_back();
    cout << cars.size();
    cout << cars.empty();

    for (int i = 0; i < cars.size(); i++) {
        cout << cars[i] << "\n";
    }

    for (string car : cars) {
        cout << car << "\n";
    }

    // Create a vector iterator called it
    vector<string>::iterator it;

    // Loop through the vector with the iterator
    for (it = cars.begin(); it != cars.end(); ++it) {
        cout << *it << "\n";
    }

    // Loop through vector elements
    for (auto it = cars.begin(); it != cars.end(); ) {
        if (*it == "BMW") {
        it = cars.erase(it); // Remove the BMW element
        } else {
        ++it;
        }
    }

    // Print vector elements
    for (const string& car : cars) {
        cout << car << "\n";
    }

    // Iterate in reverse order
    for (auto it = cars.rbegin(); it != cars.rend(); ++it) {
        cout << *it << "\n";
    }

    // Sort cars in alphabetical order
    sort(cars.begin(), cars.end());

    // Print cars in alphabetical order
    for (string car : cars) {
        cout << car << "\n";
    }

    // Create a vector called numbers that will store integers
    vector<int> numbers = {1, 7, 3, 5, 9, 2};

    // Sort numbers numerically in reverse order
    sort(numbers.rbegin(), numbers.rend());

    for (int num : numbers) {
    cout << num << "\n";
    }

    // Search for the number 3
    auto it2 = find(numbers.begin(), numbers.end(), 3);

    // Constant pointer
    int high_score = 100;
    int *const score_ptr = { &high_score }; // The pointer itself cannot change, but the value it points to can

    // Pointer to constant
    int low_score = 65;
    const int *score_ptr2 = { &low_score }; // The value it points to cannot change, but the pointer itself can

    // Constant pointer to constant
    const int constant_number = 100;
    const int *const constant_ptr = { &constant_number }; // The pointer itself cannot change, and the value it points to cannot change

    // Returning a pointer from a function
    // Returning a parameter from a function
    // int *find(int *array, int size, int value) {
    //   for (int i = 0; i < size; i++) {
    //    if (array[i] == value) {
    //     return &array[i];
    // }
    // Returning dynamically allocated memory from a function
    // int *allocate_memory() {
    //   return new int;
    // }
    // Never return a pointer to a local variable
    // int *get_local_variable() {
    //  int value = 100;
    //  return &value; // This is a bad idea
    // }
    //
    // Potential Pointer pitfalls:
    // Dangling pointers: 2 pointers pointing to the same memory location, one pointer is deleted, the other pointer is now pointing to invalid memory
    // Dangling pointers: pointer pointing to a local variable that goes out of scope
    // Memory leaks
    // Uninitialized pointers
    // Not checking if new failed
    // Dereferencing null pointers
    // Not checking for null pointers
    // Not deleting dynamically allocated memory
    // Deleting memory more than once
    // Not using references instead of pointers

    vector<string> stooges = {"John", "Mary", "Steve", "Anna", "Joe"};
    for (auto &str : stooges) {
        str = "Funny";
    }

    for (auto const &str : stooges) {
        cout << str << endl;
    }

    // Dereferencing a pointer then use the arrow operator:
    // (*ptr).member
    // ptr->member
    // (*ptr).member = ptr->member
    // Example with a class object:
    // (*ptr).set_name("John")
    // ptr->set_name("John")
    // (*ptr).set_name("John") = ptr->set_name("John")

    // Constructor initialization list House example:
    // House::House(string color, int rooms, int windows) : color{color}, rooms{rooms}, windows{windows} {}

    // Delegating constructors:
    // House::House(string color, int rooms, int windows) : color{color}, rooms{rooms}, windows{windows} {}
    // House::House() : House{"white", 5, 10} {}
    // House::House(string color) : House{color, 5, 10} {}

    // Copy constructor:
    // House::House(const House &source) : color{source.color}, rooms{source.rooms}, windows{source.windows} {}
    // House::House(const House &source) : House{source.color, source.rooms, source.windows} {}
    // House::House(const House &source) : House{source} {}

    // Copy constructor with deep copy:
    // Deep::Deep(int d) {
    // data = new int;
    // *data = d;
    // }
    // Deep::Deep(const Deep &source) : Deep{*source.data} {}
    // Deep::~Deep() {
    // delete data;
    // }

    // Move constructor:
    // Move::Move(Move &&source) : data{source.data} {
    // source.data = nullptr;
    // }

    // What is r-value reference? Give explanation and example:
    // An r-value reference is a reference that binds to an r-value. An r-value is a temporary object that is created by the compiler and is short-lived. An r-value reference is declared using the && syntax. An r-value reference can be used to move the resources from one object to another object. An r-value reference is used to implement move semantics in C++.
    // Example:
    // int x = 10;
    // int &&r = 10;
    // int &&r = x + 10;
    // int &&r = std::move(x);
    // int &&r = std::move(obj);
    // int &&r = std::move(obj.get_data());

    vector<Move> vec;
    // Move constructor is called for the temporary r-values
    vec.push_back(Move{10});
    vec.push_back(Move{20});
    for (const auto &v : vec) {
        cout << v << endl;
    }

    printString("Hello"); // Works fine, "Hello" is an r-value
    std::string s = "World";
    printString(std::move(s)); // Use std::move to convert l-value to r-value reference

    // method that use copy constructor:
    // void display_house(House house) {
    //  cout << house.color << house.rooms << house.windows;
    // }

    // Why use a constructor initialization list?
    // Avoids extra overhead of initializing variables twice
    // Can initialize const variables
    // Can initialize reference variables
    // Can call other constructors
    // Can initialize variables that don't have default constructors
    // Can initialize variables that are part of a class
}

void read_file() {
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
        // Output the text from the file
        cout << myText << endl;
    }

    // Close the file
    MyReadFile.close();
}

void printString(std::string&& str) { // r-value reference parameter
    std::cout << str << std::endl;
}