MAX_ATTEMPTS = 3

username: str = "Mina"
attempts: int = 0
middle_name: str | None = None

attempts += 1
print(f"{username} has {MAX_ATTEMPTS - attempts} attempts left")
print(f"Middle name supplied: {middle_name is not None}")
