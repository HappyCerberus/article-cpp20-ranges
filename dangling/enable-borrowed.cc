#include <iostream>
#include <ranges>
#include <algorithm>

int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

struct View1 {
    int* begin() { return data; }
    int* end() { return data+10; }
};

struct View2 {
    int* begin() { return data; }
    int* end() { return data+10; }
};

template<>
inline constexpr bool std::ranges::enable_borrowed_range<View1> = true;

int main() {
    auto sep1 = std::ranges::find(View1{}, '5');
    std::cout << *sep1 << "\n"; // OK

    auto sep2 = std::ranges::find(View2{}, '5');
    // std::cout << *sep2 << "\n"; // Compilation Error
}