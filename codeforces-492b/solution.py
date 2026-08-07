"""Solve Codeforces 492B, Vanya and Lanterns."""

import sys


def main() -> None:
    """Read the lantern positions and print the minimum common radius.

    After sorting, an interior gap of length ``gap`` is covered exactly when
    the two adjacent lanterns each reach at least ``gap / 2``.  At either end
    of the street, only one lantern can provide light, so the whole distance
    from the endpoint to the nearest lantern is required.

    We store twice the answer in ``twice_radius``.  Thus, endpoint distances
    are multiplied by two while interior gaps are used unchanged.  This keeps
    every comparison exact and postpones floating-point conversion until the
    final output.

    Sorting dominates the running time: O(n log n).  The positions use O(n)
    space (apart from Python's sorting implementation).
    """
    data = list(map(int, sys.stdin.buffer.read().split()))
    n, street_length = data[0], data[1]
    positions = data[2 : 2 + n]
    positions.sort()

    # The uncovered prefixes and suffixes each need twice their length when
    # expressed in units of twice the required radius.
    twice_radius = max(
        2 * positions[0],
        2 * (street_length - positions[-1]),
    )

    # For an interior gap, the two neighboring lanterns meet in the middle,
    # so the gap itself equals twice the radius needed to cover it.
    for left, right in zip(positions, positions[1:]):
        twice_radius = max(twice_radius, right - left)

    # The doubled value is at most 2 * 10^9, and division by two yields an
    # integer or a half-integer, both exactly representable as a float.
    print(f"{twice_radius / 2:.10f}")


if __name__ == "__main__":
    main()
