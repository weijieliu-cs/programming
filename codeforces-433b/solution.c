/*
 * Solve Codeforces 433B, Kuriyama Mirai's Stones.
 *
 * Algorithm:
 * 1. Preserve the costs in input order and make a sorted copy.
 * 2. Build a prefix-sum array for each order.  prefix[k] contains the sum of
 *    positions 1 through k, and prefix[0] is zero.
 * 3. Select the original prefix for a type-1 query or the sorted prefix for a
 *    type-2 query.  The inclusive range sum [left, right] is then
 *    prefix[right] - prefix[left - 1].
 *
 * Correctness:
 * The original prefix difference cancels all costs before left and retains
 * exactly v_left through v_right, so it answers type-1 queries.  After sorting,
 * position i contains u_i, the i-th cheapest cost.  The sorted prefix
 * difference therefore retains exactly u_left through u_right and answers
 * type-2 queries.  The algorithm chooses the corresponding prefix for every
 * query, hence every printed range sum is correct.
 *
 * Complexity:
 * Sorting takes O(n log n), prefix construction takes O(n), and each query
 * takes O(1).  The arrays use O(n) memory.  long long is necessary because a
 * sum can be as large as 10^14, which does not fit in a 32-bit integer.
 */

#include <stdio.h>
#include <stdlib.h>

/* qsort requires a three-way comparison.  Comparisons avoid subtraction,
 * whose result could overflow for more general long long inputs. */
static int compare_long_long(const void *left, const void *right) {
    const long long a = *(const long long *)left;
    const long long b = *(const long long *)right;
    return (a > b) - (a < b);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    /* Index zero is reserved so all problem indices can stay 1-based. */
    long long *original = malloc((size_t)(n + 1) * sizeof(*original));
    long long *sorted = malloc((size_t)(n + 1) * sizeof(*sorted));
    long long *original_prefix =
        malloc((size_t)(n + 1) * sizeof(*original_prefix));
    long long *sorted_prefix =
        malloc((size_t)(n + 1) * sizeof(*sorted_prefix));

    if (original == NULL || sorted == NULL || original_prefix == NULL ||
        sorted_prefix == NULL) {
        free(original);
        free(sorted);
        free(original_prefix);
        free(sorted_prefix);
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &original[i]);
        sorted[i] = original[i];
    }

    qsort(sorted + 1, (size_t)n, sizeof(*sorted), compare_long_long);

    original_prefix[0] = 0;
    sorted_prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        original_prefix[i] = original_prefix[i - 1] + original[i];
        sorted_prefix[i] = sorted_prefix[i - 1] + sorted[i];
    }

    int query_count;
    scanf("%d", &query_count);
    for (int query = 0; query < query_count; ++query) {
        int type;
        int left;
        int right;
        scanf("%d%d%d", &type, &left, &right);

        /* The selected prefix represents exactly the order named by type. */
        const long long *prefix =
            (type == 1) ? original_prefix : sorted_prefix;
        printf("%lld\n", prefix[right] - prefix[left - 1]);
    }

    free(original);
    free(sorted);
    free(original_prefix);
    free(sorted_prefix);
    return 0;
}
