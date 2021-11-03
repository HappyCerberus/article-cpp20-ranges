#include <iostream>
#include <range/v3/algorithm/generate_n.hpp>

int main() {
    ranges::generate_n(
        std::ostream_iterator<std::string>(std::cout, "\n"), 
        20,
        [i = 0]() mutable {
            i++;
            std::string result;
            if (i % 3 == 0) result += "Fizz";
            if (i % 5 == 0) result += "Buzz";
            if (result.empty()) return std::to_string(i);
            return result;
    });
}