#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

class Logger {
public:
    explicit Logger(const std::string& path) : file_{path} {
        if (!file_) throw std::runtime_error("could not open log file");
    }
    void write(const std::string& message) { file_ << message << '\n'; }
private:
    std::ofstream file_; // closes automatically when Logger is destroyed
};

int main() {
    Logger log{"example.log"};
    log.write("Resource lifetime is tied to object lifetime.");

    auto number = std::make_unique<int>(42); // exclusive ownership
    std::cout << *number << '\n';
} // file and unique_ptr clean up automatically, including on exceptions
