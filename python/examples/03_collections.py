from collections.abc import Iterable


def summarize(scores: Iterable[int]) -> dict[str, int]:
    values = list(scores)
    return {
        "count": len(values),
        "passing": sum(score >= 60 for score in values),
        "highest": max(values, default=0),
    }


def main() -> None:
    scores = [55, 72, 90, 72]
    unique_scores = set(scores)
    print(summarize(scores))
    print(f"Unique scores: {sorted(unique_scores)}")


if __name__ == "__main__":
    main()
