#include <iostream>
#include <string>

int main() {
    constexpr int maxAttempts{3};
    const std::string user{"Mina"};
    int attempts{0};
    double ratio{2.5};

    ++attempts;
    const auto roundedDown = static_cast<int>(ratio); // explicit truncation
    std::cout << user << " has " << maxAttempts - attempts
              << " attempts left; ratio converted to " << roundedDown << '\n';
}
