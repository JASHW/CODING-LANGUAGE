#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int main() {
    const std::array<int, 3> fixed{4, 2, 7};
    std::vector<int> scores(fixed.begin(), fixed.end());
    scores.push_back(5);
    std::sort(scores.begin(), scores.end());

    const auto passing = std::count_if(scores.begin(), scores.end(),
                                       [](int score) { return score >= 5; });
    std::cout << "Passing scores: " << passing << '\n';
    for (const int score : scores) std::cout << score << ' ';
    std::cout << '\n';
}
