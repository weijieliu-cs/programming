import sys


def main() -> None:
    # Read all integers at once.  The input layout is:
    # n, followed by n boys' skills, then m, followed by m girls' skills.
    data = list(map(int, sys.stdin.buffer.read().split()))
    n = data[0]
    boys = sorted(data[1 : n + 1])
    m_index = n + 1
    m = data[m_index]
    girls = sorted(data[m_index + 1 : m_index + 1 + m])

    # Sorting lets us process both groups from the lowest skill upward.  At any
    # point, "boy" and "girl" identify the lowest-skilled unmatched students.
    boy = 0
    girl = 0
    pairs = 0

    while boy < n and girl < m:
        if abs(boys[boy] - girls[girl]) <= 1:
            # These two students are compatible.  Pairing the two smallest
            # remaining compatible skills cannot reduce the number of future
            # pairs, so consume both students.
            pairs += 1
            boy += 1
            girl += 1
        elif boys[boy] < girls[girl]:
            # The current boy is more than one level below the current girl.
            # Every later girl has at least as much skill, so this boy can
            # never be paired and may safely be skipped.
            boy += 1
        else:
            # Symmetrically, the current girl is too far below this boy and
            # every later boy, so she can never participate in a valid pair.
            girl += 1

    # Each successful greedy match increases this counter exactly once.
    print(pairs)


if __name__ == "__main__":
    main()
