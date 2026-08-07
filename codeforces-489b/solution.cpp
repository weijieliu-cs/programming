#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
    // Fast standard I/O is sufficient for the simple four-line input format.
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Read the skill values for both groups.
    int n;
    std::cin >> n;
    std::vector<int> boys(n);
    for (int &skill : boys) {
        std::cin >> skill;
    }

    int m;
    std::cin >> m;
    std::vector<int> girls(m);
    for (int &skill : girls) {
        std::cin >> skill;
    }

    // Sorting allows a greedy left-to-right scan.  At each step we only need
    // to compare the lowest-skilled boy and girl who have not been processed.
    std::sort(boys.begin(), boys.end());
    std::sort(girls.begin(), girls.end());

    // "boy" and "girl" point to the smallest currently unmatched skills.
    int boy = 0;
    int girl = 0;
    int pairs = 0;

    while (boy < n && girl < m) {
        if (std::abs(boys[boy] - girls[girl]) <= 1) {
            // Match the two smallest compatible students.  This choice leaves
            // all students with larger skills available for subsequent pairs.
            ++pairs;
            ++boy;
            ++girl;
        } else if (boys[boy] < girls[girl]) {
            // This boy is more than one level below the current girl.  Because
            // every later girl has at least this skill, he cannot be matched.
            ++boy;
        } else {
            // This girl is too far below the current boy and all later boys,
            // so skipping her cannot remove any possible valid pair.
            ++girl;
        }
    }

    // The greedy scan counts the maximum number of disjoint compatible pairs.
    std::cout << pairs << '\n';
    return 0;
}
