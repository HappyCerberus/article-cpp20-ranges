#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

int main() {
    namespace rnv = std::ranges::views;
    std::vector<int> dt = {1, 2, 3, 4, 5, 6, 7};
    auto odd = [](std::integral auto v) { return v % 2 == 1; };
    for (auto& v : dt | rnv::filter(odd)) {
        v *= 2;
    }
    
    std::ranges::copy(dt, std::ostream_iterator<int>(std::cout, ", "));
    std::cout << "\n";
}