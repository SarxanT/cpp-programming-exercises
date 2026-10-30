# C++ Programming Exercises

A collection of learning exercises in **C++17** exploring object-oriented programming and core data structures. These projects started as coursework/practice and have been reorganized with clearer file names, English comments, and targeted fixes.

> **Scope:** Educational examples, not production applications. The code is deliberately kept close to its original learning objectives.

## Exercises

| File | Focus | What it demonstrates |
| --- | --- | --- |
| [`contact_database.cpp`](contact_database.cpp) | Contact database | Vectors, classes, searching, erase-remove |
| [`student_priority_queue.cpp`](student_priority_queue.cpp) | Student priority queue | Templates, object comparison, queue behavior |
| [`vehicle_inheritance.cpp`](vehicle_inheritance.cpp) | Vehicle inheritance | Inheritance, virtual methods, composition |
| [`computer_store.cpp`](computer_store.cpp) | Computer inventory | Classes, copying, operator overloading |
| [`bank_debtors.cpp`](bank_debtors.cpp) | Debtor management | Classes, records, filtering |
| [`string_and_integer_array.cpp`](string_and_integer_array.cpp) | Collection exercises | Strings, lists, container operations |

## Getting started

Each `.cpp` file is an **independent program** with its own `main()`. Compile them separately using a C++17 compiler:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic contact_database.cpp -o contact_database
./contact_database
```

For an all-files local smoke check on Linux or macOS:

```bash
bash scripts/check_cpp.sh
```

Windows users can compile individual programs with MSYS2/MinGW-w64 or another C++17 toolchain.

## Validation

- The six programs passed a C++17 compilation test and simple execution smoke tests during refurbishment (October 2026).
- They have **not** been comprehensively unit-tested; uncalled methods and edge cases may need further work.
- An automated GitHub Actions workflow runs the same basic build/run checks after publication.

## Learning outcomes

- Model data with C++ classes and constructors.
- Practice inheritance, containers, and data filtering.
- Improve code clarity with descriptive names and documentation.
- Learn to test and maintain an existing codebase.

## Provenance

Refactored learning exercises. Historical assignment dates are not represented as GitHub commit dates; new commits reflect the actual publication and maintenance work.

## License

No open-source license has been selected yet. Please contact the repository owner before reusing the code outside permitted GitHub viewing/forking functionality.
