from collections.abc import Iterator


def squares_below(limit: int) -> Iterator[int]:
    for number in range(limit):
        yield number * number


def main() -> None:
    even_squares = [value for value in squares_below(10) if value % 2 == 0]
    print(even_squares)


if __name__ == "__main__":
    main()
