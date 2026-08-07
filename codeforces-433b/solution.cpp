/*
 * Solve Codeforces 433B, Kuriyama Mirai's Stones.
 *
 * The sequence is never updated, so we preprocess two prefix-sum arrays: one
 * for the input order and one for a non-decreasing copy.  If prefix[k] is the
 * sum of positions 1 through k, an inclusive range sum [left, right] equals
 * prefix[right] - prefix[left - 1].
 *
 * Correctness proof:
 * For type 1, original_prefix[right] contains v_1 + ... + v_right, while
 * original_prefix[left - 1] contains precisely the terms preceding v_left.
 * Their difference is therefore v_left + ... + v_right.  For type 2, sorting
 * places u_i, the i-th cheapest cost, at position i.  Applying the identical
 * prefix difference to sorted_prefix gives u_left + ... + u_right.  Since the
 * algorithm selects the appropriate prefix according to the query type, it
 * returns the required sum for every query.
 *
 * Sorting takes O(n log n), constructing both prefixes takes O(n), and each
 * query takes O(1).  The vectors require O(n) memory.  long long safely stores
 * the maximum possible sum of 10^14.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // Index zero is intentionally unused to match the problem's 1-based ranges.
    std::vector<long long> original(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> original[i];
    }

    std::vector<long long> sorted = original;
    std::sort(sorted.begin() + 1, sorted.end());

    std::vector<long long> original_prefix(n + 1, 0);
    std::vector<long long> sorted_prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        original_prefix[i] = original_prefix[i - 1] + original[i];
        sorted_prefix[i] = sorted_prefix[i - 1] + sorted[i];
    }

    int query_count;
    std::cin >> query_count;
    while (query_count-- > 0) {
        int type;
        int left;
        int right;
        std::cin >> type >> left >> right;

        // Type 1 asks about input order; type 2 asks about sorted order.
        const std::vector<long long>& prefix =
            (type == 1) ? original_prefix : sorted_prefix;
        std::cout << prefix[right] - prefix[left - 1] << '\n';
    }

    return 0;
}
