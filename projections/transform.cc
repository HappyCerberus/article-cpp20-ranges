#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> dt = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> result;
    std::ranges::transform(dt, 
                       dt | std::views::reverse,
                       std::back_inserter(result),
                       std::minus<void>(),
                       [](int v) { return v*v; },
                       [](int v) { return v*v; });
    std::ranges::copy(result, 
                  std::ostream_iterator<int>(std::cout, ","));
}