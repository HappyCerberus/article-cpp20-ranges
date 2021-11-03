#include <iostream>
#include <ranges>
#include <list>
#include <algorithm>

int main() {
    std::list<int> dt = {1, 4, 2, 3};
    std::ranges::sort(dt.begin(), dt.end());
    std::ranges::copy(dt.begin(), dt.end(), std::ostream_iterator<int>(std::cout, ","));
}