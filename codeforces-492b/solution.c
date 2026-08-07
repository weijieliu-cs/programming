#include <stdio.h>
#include <stdlib.h>

/* Compare two long long positions for qsort without subtracting them.
 * Branch comparisons avoid a narrowing conversion and remain safe even if
 * the allowed coordinate range is increased in the future. */
static int compare_positions(const void *lhs, const void *rhs) {
    const long long left = *(const long long *)lhs;
    const long long right = *(const long long *)rhs;
    return (left > right) - (left < right);
}

int main(void) {
    int n;
    long long street_length;

    if (scanf("%d %lld", &n, &street_length) != 2) {
        return 0;
    }

    /* n is at most 1000, but dynamic allocation keeps the implementation
     * independent of a hard-coded array limit. */
    long long *positions = malloc((size_t)n * sizeof(*positions));
    if (positions == NULL) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        if (scanf("%lld", &positions[i]) != 1) {
            free(positions);
            return 0;
        }
    }

    qsort(positions, (size_t)n, sizeof(*positions), compare_positions);

    /* Store twice the required radius so all comparisons stay integral.
     * An endpoint has only one nearby lantern, hence its distance is doubled.
     * long long safely holds these doubled values (at most 2 * 10^9). */
    long long twice_radius = 2LL * positions[0];
    const long long right_endpoint = 2LL * (street_length - positions[n - 1]);
    if (right_endpoint > twice_radius) {
        twice_radius = right_endpoint;
    }

    /* Inside the street, adjacent lanterns cover a gap from both sides.  They
     * meet when each radius is half the gap, so the gap length itself is the
     * needed doubled radius.  Taking the maximum handles every dark segment. */
    for (int i = 1; i < n; ++i) {
        const long long gap = positions[i] - positions[i - 1];
        if (gap > twice_radius) {
            twice_radius = gap;
        }
    }

    /* The sorted gaps and the two endpoint distances cover every point of the
     * street, and each maximum candidate is necessary.  Therefore their
     * maximum is exactly the minimum feasible radius. */
    printf("%.10f\n", (double)twice_radius / 2.0);

    free(positions);
    /* Sorting costs O(n log n) time; scanning the gaps costs O(n).  The array
     * uses O(n) space, while all other storage is constant. */
    return 0;
}
