# Programming

This repository contains Codeforces problem statements and independently
runnable solutions written in C++.

## Repository structure

Each problem has its own directory at the repository root:

```text
codeforces-<problem-id>/
|-- problem.md
`-- solution.cpp
```

`problem.md` records the original problem statement and its canonical
Codeforces URL. `solution.cpp` includes detailed comments explaining the
approach and correctness.

## Running a solution

The following examples use Codeforces 489B. Replace `input.txt` with a file
containing valid input for the problem.

```sh
mkdir -p build
c++ -std=c++17 -Wall -Wextra -Wpedantic \
  codeforces-489b/solution.cpp -o build/codeforces-489b-cpp
build/codeforces-489b-cpp < input.txt
```

## License

Original solution code and repository-authored documentation are available
under the [MIT License](LICENSE).

Codeforces problem statements and other third-party material are excluded from
that license and remain the property of their respective copyright holders.
