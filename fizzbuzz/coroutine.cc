#include <iostream>
#include <range/v3/experimental/utility/generator.hpp>
#include <range/v3/view/take.hpp>

namespace rnv = ranges::views;

ranges::experimental::generator<std::string> fizzbuzz() {
    for (int i = 1; ; i++) {
        std::string result;
        if (i % 3 == 0) result += "Fizz";
        if (i % 5 == 0) result += "Buzz";
        if (result.empty()) co_yield std::to_string(i);
        else co_yield result;
    }
}

int main() {
    for (auto v : fizzbuzz() | rnv::take(20)) {
        std::cout << v << "\n";
    }
}