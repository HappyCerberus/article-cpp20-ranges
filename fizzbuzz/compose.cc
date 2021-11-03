#include <string>
#include <array>
#include <iostream>

#include <range/v3/algorithm/copy_n.hpp>
#include <range/v3/view/cycle.hpp>
#include <range/v3/view/drop.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/zip_with.hpp>

namespace rnv = ranges::views;

int main() {
    std::array<std::string, 3> fizz{"", "", "Fizz"};
    std::array<std::string, 5> buzz{"", "", "", "", "Buzz"};

    const auto inf_fizz = fizz | rnv::cycle;
    const auto inf_buzz = buzz | rnv::cycle;

    const auto inf_fizzbuzz = rnv::zip_with(std::plus<>(), inf_fizz, inf_buzz);
    
    const auto indices = rnv::indices | rnv::drop(1);

    const auto final_range = rnv::zip_with(
        [](auto i, auto s) { if (s.empty()) return std::to_string(i); return s; },
        indices,
        inf_fizzbuzz
    );

    ranges::copy_n(ranges::begin(final_range), 20, 
        std::ostream_iterator<std::string>(std::cout, "\n"));
}