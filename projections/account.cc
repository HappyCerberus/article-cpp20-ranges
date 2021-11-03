#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>

struct Account {
    std::string owner;
    double value() const { return owner.length(); }
    double base() const { return 3.0; }
};

std::ostream& operator<<(std::ostream& os, const Account& acc) {
    os << acc.owner;
    return os;
}


int main() {
    std::vector<Account> acc = {{"Nicolas"}, {"Adam"}, {"Peter"}};

    std::ranges::sort(acc,{},&Account::owner);
    std::ranges::copy(acc, std::ostream_iterator<Account>(std::cout, ", "));
    std::cout << "\n";

    std::ranges::sort(acc,{},&Account::value);
    std::ranges::copy(acc, std::ostream_iterator<Account>(std::cout, ", "));
    std::cout << "\n";

    std::ranges::sort(acc,{},[](const auto& a) { 
        return a.value()+a.base(); 
    });
    std::ranges::copy(acc, std::ostream_iterator<Account>(std::cout, ", "));
    std::cout << "\n";
}