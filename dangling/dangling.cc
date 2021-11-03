#include <iostream>
#include <ranges>
#include <algorithm>

int main() {
    auto good = "1234567890";
    auto sep1 = std::ranges::find(std::string_view(good), '0');
    std::cout << *sep1 << "\n";

    auto bad = 1234567890;
    auto sep2 = std::ranges::find(std::to_string(bad), '0');
    // std::cout << *sep2 << "\n"; // Compilation Error
}