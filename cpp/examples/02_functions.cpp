#include <iostream>
#include <string>

int clamp(int value, int low = 0, int high = 100) {
    if (value < low) return low;
    if (value > high) return high;
    return value;
}

void increment(int& value) { ++value; }

void print(const std::string& text) { std::cout << text << '\n'; }

std::string greeting(const std::string& name) { return "Hello, " + name; }

int main() {
    int score{105};
    increment(score);
    print(greeting("Mina"));
    std::cout << clamp(score) << '\n';
}
