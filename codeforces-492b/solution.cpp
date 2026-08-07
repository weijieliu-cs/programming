#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long street_length;
    if (!(std::cin >> n >> street_length)) {
        return 0;
    }

    // Sorting makes every potentially dark interior segment appear between
    // consecutive entries. long long safely stores coordinates and their
    // doubled endpoint distances, whose maximum is only 2 * 10^9 here.
    std::vector<long long> positions(n);
    for (long long &position : positions) {
        std::cin >> position;
    }
    std::sort(positions.begin(), positions.end());

    // Keep twice the answer as an integer. At an endpoint there is no lantern
    // on the street's other side, so the nearest lantern must cover the entire
    // endpoint distance; this distance is doubled in twice-radius units.
    long long twice_radius = std::max(
        2LL * positions.front(),
        2LL * (street_length - positions.back()));

    // Adjacent lanterns cover an interior gap from opposite directions. A
    // radius equal to half the gap makes their illuminated intervals meet, so
    // the full gap is the corresponding candidate for twice the radius.
    for (int i = 1; i < n; ++i) {
        twice_radius = std::max(twice_radius, positions[i] - positions[i - 1]);
    }

    // The endpoint candidates and all consecutive gaps partition the street's
    // possible dark regions. Each candidate is necessary, while their maximum
    // is sufficient to cover every region, proving that the result is minimal.
    std::cout << std::fixed << std::setprecision(10)
              << static_cast<double>(twice_radius) / 2.0 << '\n';

    // Sorting takes O(n log n) time, the scan takes O(n), and the positions
    // vector uses O(n) memory; all remaining state uses O(1) memory.
    return 0;
}
