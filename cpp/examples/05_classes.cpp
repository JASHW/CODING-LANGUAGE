#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

class BankAccount {
public:
    BankAccount(std::string owner, int openingCents)
        : owner_{std::move(owner)}, balanceCents_{openingCents} {
        if (openingCents < 0) throw std::invalid_argument("negative opening balance");
    }

    const std::string& owner() const { return owner_; }
    int balanceCents() const { return balanceCents_; }

    void deposit(int cents) {
        if (cents <= 0) throw std::invalid_argument("deposit must be positive");
        balanceCents_ += cents;
    }

private:
    std::string owner_;
    int balanceCents_;
};

int main() {
    BankAccount account{"Mina", 1250};
    account.deposit(250);
    std::cout << account.owner() << " has " << account.balanceCents() << " cents\n";
}
