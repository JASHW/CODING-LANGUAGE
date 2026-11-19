from pathlib import Path


def count_nonempty_lines(path: Path) -> int:
    with path.open(encoding="utf-8") as file:
        return sum(bool(line.strip()) for line in file)


def main() -> None:
    path = Path("sample.txt")
    try:
        print(count_nonempty_lines(path))
    except FileNotFoundError:
        print(f"Create {path} to try this example.")


if __name__ == "__main__":
    main()
