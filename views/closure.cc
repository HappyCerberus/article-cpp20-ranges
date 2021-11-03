#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

int main() {
    namespace rnv = std::ranges::views;
    std::vector<int> dt = {1, 2, 3, 4, 5, 6, 7};
    for (int v : dt | rnv::reverse | rnv::take(3) | rnv::reverse) {
        std::cout << v << ", ";
    }
    std::cout << "\n";
}