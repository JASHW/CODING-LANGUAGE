#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Book {
public:
    Book(std::string title, int pages)
        : title_{std::move(title)}, pages_{pages} {}
    const std::string& title() const { return title_; }
    int pages() const { return pages_; }
private:
    std::string title_;
    int pages_;
};

class Library {
public:
    void add(Book book) { books_.push_back(std::move(book)); }
    void printTitles() const {
        for (const Book& book : books_) std::cout << book.title() << '\n';
    }
    int totalPages() const {
        int total{0};
        for (const Book& book : books_) total += book.pages();
        return total;
    }
private:
    std::vector<Book> books_; // Library has Books: composition
};

int main() {
    Library library;
    library.add(Book{"C++ Basics", 220});
    library.add(Book{"Object Design", 180});
    library.printTitles();
    std::cout << "Total pages: " << library.totalPages() << '\n';
}
