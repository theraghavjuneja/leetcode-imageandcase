// Strings in C++ or any language can also do ascii comparison.
// i.e. if i do string a>b. it will return true if a is lexiographically(alphabetically bigger)
// or Acc to ascii value
// 'a' (ASCII 97) is less than 'b' (ASCII 98), so "apple" < "banana" is true, and hence "apple" > "banana" is false.


#include <iostream>
#include <string>

int main() {
    std::string a = "zebra";
    std::string b = "apple";
    std::cout << (a > b) << std::endl;  // prints 1 (true)
    return 0;
}
