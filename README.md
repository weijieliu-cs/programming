# Programming

This repository contains Codeforces problem statements and independently
runnable solutions written in Python, C, and C++.

## Repository structure

Each problem has its own directory at the repository root:

```text
codeforces-<problem-id>/
|-- problem.md
|-- solution.py
|-- solution.c
`-- solution.cpp
```

`problem.md` records the original problem statement and its canonical
Codeforces URL. The three solution files implement the same algorithm in their
respective languages and include detailed comments explaining the approach and
correctness.

## Problems

| Problem | Title | Statement | Solutions |
| --- | --- | --- | --- |
| 489B | BerSU Ball | [Problem](codeforces-489b/problem.md) | [Python](codeforces-489b/solution.py) · [C](codeforces-489b/solution.c) · [C++](codeforces-489b/solution.cpp) |

## Running a solution

The following examples use Codeforces 489B. Replace `input.txt` with a file
containing valid input for the problem.

### Python

```sh
python3 codeforces-489b/solution.py < input.txt
```

### C

```sh
cc -std=c11 -Wall -Wextra -Wpedantic \
  codeforces-489b/solution.c -o /tmp/codeforces-489b-c
/tmp/codeforces-489b-c < input.txt
```

### C++

```sh
c++ -std=c++17 -Wall -Wextra -Wpedantic \
  codeforces-489b/solution.cpp -o /tmp/codeforces-489b-cpp
/tmp/codeforces-489b-cpp < input.txt
```

## License

Original solution code and repository-authored documentation are available
under the [MIT License](LICENSE).

Codeforces problem statements and other third-party material are excluded from
that license and remain the property of their respective copyright holders.
