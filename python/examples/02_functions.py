def clamp(value: int, low: int = 0, high: int = 100) -> int:
    if low > high:
        raise ValueError("low must not exceed high")
    return min(max(value, low), high)


def add_one(value: int) -> int:
    return value + 1


def main() -> None:
    score = 105
    print(clamp(add_one(score)))


if __name__ == "__main__":
    main()
