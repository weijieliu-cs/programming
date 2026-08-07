"""Solve Codeforces 433B, Kuriyama Mirai's Stones.

The original order and the non-decreasing order are fixed before any query is
asked.  We therefore build one prefix-sum array for each order.  For either
array, the sum on the inclusive interval [left, right] is
prefix[right] - prefix[left - 1].

Correctness:
- original_prefix[k] is the sum of the first k costs in their input order, so
  subtracting original_prefix[left - 1] from original_prefix[right] leaves
  exactly v_left through v_right.  This answers every type-1 query.
- sorted_costs stores all costs in non-decreasing order.  Thus its k-th value
  is u_k from the statement, and the same prefix-sum subtraction on
  sorted_prefix leaves exactly u_left through u_right.  This answers every
  type-2 query.
Consequently, the selected prefix array produces the required answer for every
query.

Sorting costs O(n log n); building the prefixes costs O(n), and each of the m
queries costs O(1).  The two prefix arrays use O(n) additional memory.
"""

import sys


def build_prefix(values: list[int]) -> list[int]:
    """Return prefix sums with prefix[0] = 0 for convenient 1-based ranges."""
    prefix = [0]
    for value in values:
        prefix.append(prefix[-1] + value)
    return prefix


def main() -> None:
    # Token-based input handles arbitrary whitespace and keeps large inputs fast.
    tokens = list(map(int, sys.stdin.buffer.read().split()))
    position = 0

    n = tokens[position]
    position += 1
    costs = tokens[position : position + n]
    position += n

    # Keep independent prefixes because sorting must not destroy the input order.
    original_prefix = build_prefix(costs)
    sorted_prefix = build_prefix(sorted(costs))

    query_count = tokens[position]
    position += 1
    answers: list[str] = []

    for _ in range(query_count):
        query_type, left, right = tokens[position : position + 3]
        position += 3

        # Type 1 uses input order; type 2 uses non-decreasing cost order.
        prefix = original_prefix if query_type == 1 else sorted_prefix
        answers.append(str(prefix[right] - prefix[left - 1]))

    sys.stdout.write("\n".join(answers))


if __name__ == "__main__":
    main()
