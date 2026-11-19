# 10. Modules and packages

A Python file is a module. Import names explicitly and use the standard library before adding third-party dependencies.

```python
from pathlib import Path
import math

root = math.sqrt(81)
config_path = Path("config.json")
```

Avoid wildcard imports (`from module import *`); they obscure where names came from. Keep reusable code in modules and executable entry points in scripts.

```python
def main() -> None:
    print("Run the program")


if __name__ == "__main__":
    main()
```

The guard lets a file be imported without running its command-line behavior. A directory of related modules can be organized as a package. Run scripts from the project root or use `python -m package.module` so imports resolve consistently.
