#include <stdio.h>
#include <stdlib.h>

/* qsort comparator that orders skill values from smallest to largest. */
static int compare_ints(const void *left, const void *right) {
    const int a = *(const int *)left;
    const int b = *(const int *)right;
    return (a > b) - (a < b);
}

int main(void) {
    /* The constraints guarantee that neither group contains more than 100
       students, so fixed-size arrays are sufficient. */
    int n;
    int boys[100];
    int m;
    int girls[100];

    /* Read the boys' skills, followed by the girls' skills. */
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        (void)scanf("%d", &boys[i]);
    }

    (void)scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        (void)scanf("%d", &girls[i]);
    }

    /* Once both arrays are sorted, the smallest unmatched boy and girl can
       be considered greedily.  Sorting dominates the O(n + m) scan below. */
    qsort(boys, (size_t)n, sizeof(boys[0]), compare_ints);
    qsort(girls, (size_t)m, sizeof(girls[0]), compare_ints);

    /* These indices always point to the lowest-skilled unmatched students. */
    int boy = 0;
    int girl = 0;
    int pairs = 0;

    while (boy < n && girl < m) {
        if (abs(boys[boy] - girls[girl]) <= 1) {
            /* Pairing the two smallest compatible students preserves all
               opportunities for the remaining, no-less-skilled students. */
            ++pairs;
            ++boy;
            ++girl;
        } else if (boys[boy] < girls[girl]) {
            /* This boy is more than one level below the current girl.  Since
               later girls have even greater or equal skill, he can never be
               matched and can be discarded safely. */
            ++boy;
        } else {
            /* The current girl is likewise too far below this boy and every
               later boy, so no valid future pair can contain her. */
            ++girl;
        }
    }

    /* "pairs" is the maximum number of disjoint compatible pairs. */
    printf("%d\n", pairs);
    return 0;
}
