<!--
Canonical URL: https://codeforces.com/problemset/problem/492/B
Problem ID: 492B
time limit per test: 1 second
memory limit per test: 256 megabytes
-->

# B. Vanya and Lanterns

Vanya walks late at night along a straight street of length $l$, lit by $n$ lanterns. Consider the coordinate system with the beginning of the street corresponding to the point $0$, and its end corresponding to the point $l$. Then the $i$-th lantern is at the point $a_i$. The lantern lights all points of the street that are at the distance of at most $d$ from it, where $d$ is some positive number, common for all lanterns.

Vanya wonders: what is the minimum light radius $d$ should the lanterns have to light the whole street?

## Input

The first line contains two integers $n$, $l$ ($1 \le n \le 1000$, $1 \le l \le 10^9$) — the number of lanterns and the length of the street respectively.

The next line contains $n$ integers $a_i$ ($0 \le a_i \le l$). Multiple lanterns can be located at the same point. The lanterns may be located at the ends of the street.

## Output

Print the minimum light radius $d$, needed to light the whole street. The answer will be considered correct if its absolute or relative error doesn't exceed $10^{-9}$.

## Examples

**input**

```text
7 15
15 5 3 7 9 14 0
```

**output**

```text
2.5000000000
```

**input**

```text
2 5
2 5
```

**output**

```text
2.0000000000
```
