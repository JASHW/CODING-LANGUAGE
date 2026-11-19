from dataclasses import dataclass


@dataclass(frozen=True)
class Book:
    title: str
    pages: int


class Library:
    def __init__(self) -> None:
        self._books: list[Book] = []

    def add(self, book: Book) -> None:
        self._books.append(book)

    def total_pages(self) -> int:
        return sum(book.pages for book in self._books)

    def titles(self) -> list[str]:
        return [book.title for book in self._books]


def main() -> None:
    library = Library()
    library.add(Book("Python Basics", 220))
    library.add(Book("Object Design", 180))
    print(library.titles())
    print(library.total_pages())


if __name__ == "__main__":
    main()
