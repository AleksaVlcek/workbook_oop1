# OOP1 Workbook

My solutions to the exercises from the C++ workbook by László Kraus, as part of the Object-Oriented Programming 1 (OOP1) course at ETF.

## Structure

Exercises are grouped by topic, and each exercise has its own folder with all of its source files.

```
workbook_oop1/
├── classes/              # Exercises on classes
│   └── exercise1/
│       ├── main.cpp
│       ├── point.cpp
│       └── point.h
├── Makefile              # Universal build file for any exercise
└── README.md
```

## Building and running

A compiler with C++17 support or newer is required (e.g. `g++`), as well as `make`.

The single [Makefile](Makefile) in the root works for every exercise. It compiles all `.cpp` files in the given folder into `main.exe` inside that folder.

```bash
make run EX=classes/exercise1     # build and run
make build EX=classes/exercise1   # build only
make clean                        # delete all .exe files
```

Without `make`, the same thing by hand:

```bash
g++ -std=c++17 -Wall -Wextra -o classes/exercise1/main.exe classes/exercise1/*.cpp
./classes/exercise1/main.exe
```

## Note

These solutions are my own and may contain mistakes. Feel free to use them as a reference, but try solving the exercises on your own first.
