#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <random>

int main() {
    std::vector<int> dt = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::ranges::shuffle(dt, std::mt19937(std::random_device()()));
    auto pos = std::ranges::find(dt.begin(), std::unreachable_sentinel, 7);
    std::ranges::copy(dt.begin(), ++pos, std::ostream_iterator<int>(std::cout, ","));
}