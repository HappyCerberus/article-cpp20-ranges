#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

int main() {
    using namespace std::ranges;
    
    std::vector<int> dt = {1, 2, 3, 4, 5, 6, 7};
    for (int v : reverse_view(take_view(reverse_view(dt),3))) {
        std::cout << v << ", ";
    }
    std::cout << "\n";
}