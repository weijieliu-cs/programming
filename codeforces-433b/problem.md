<!--
Canonical URL: https://codeforces.com/problemset/problem/433/B
Problem ID: 433B
time limit per test: 2 seconds
memory limit per test: 256 megabytes
-->

# B. Kuriyama Mirai's Stones

Kuriyama Mirai has killed many monsters and got many (namely $n$) stones. She numbers the stones from $1$ to $n$. The cost of the $i$-th stone is $v_i$. Kuriyama Mirai wants to know something about these stones so she will ask you two kinds of questions:

1. She will tell you two numbers, $l$ and $r$ ($1 \le l \le r \le n$), and you should tell her $\sum_{i=l}^{r} v_i$.
2. Let $u_i$ be the cost of the $i$-th cheapest stone (the cost that will be on the $i$-th place if we arrange all the stone costs in non-decreasing order). This time she will tell you two numbers, $l$ and $r$ ($1 \le l \le r \le n$), and you should tell her $\sum_{i=l}^{r} u_i$.

For every question you should give the correct answer, or Kuriyama Mirai will say "fuyukai desu" and then become unhappy.

## Input

The first line contains an integer $n$ ($1 \le n \le 10^5$). The second line contains $n$ integers: $v_1, v_2, \dots, v_n$ ($1 \le v_i \le 10^9$) — costs of the stones.

The third line contains an integer $m$ ($1 \le m \le 10^5$) — the number of Kuriyama Mirai's questions. Then follow $m$ lines, each line contains three integers $type$, $l$ and $r$ ($1 \le l \le r \le n$; $1 \le type \le 2$), describing a question. If $type$ equal to $1$, then you should output the answer for the first question, else you should output the answer for the second one.

## Output

Print $m$ lines. Each line must contain an integer — the answer to Kuriyama Mirai's question. Print the answers to the questions in the order of input.

## Examples

**input**

```text
6
6 4 2 7 2 7
3
2 3 6
1 3 4
1 1 6
```

**output**

```text
24
9
28
```

**input**

```text
4
5 5 2 3
10
1 2 4
2 1 4
1 1 1
2 1 4
2 1 2
1 1 1
1 3 3
1 1 3
1 4 4
1 2 2
```

**output**

```text
10
15
5
15
5
5
2
12
3
5
```

## Note

Please note that the answers to the questions may overflow 32-bit integer type.
