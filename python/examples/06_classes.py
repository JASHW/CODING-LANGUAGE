class BankAccount:
    def __init__(self, owner: str, opening_cents: int = 0) -> None:
        if opening_cents < 0:
            raise ValueError("opening balance cannot be negative")
        self.owner = owner
        self._balance_cents = opening_cents

    @property
    def balance_cents(self) -> int:
        return self._balance_cents

    def deposit(self, cents: int) -> None:
        if cents <= 0:
            raise ValueError("deposit must be positive")
        self._balance_cents += cents


def main() -> None:
    account = BankAccount("Mina", 1250)
    account.deposit(250)
    print(account.owner, account.balance_cents)


if __name__ == "__main__":
    main()
