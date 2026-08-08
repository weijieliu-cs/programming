#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

class FenwickMax {
public:
    explicit FenwickMax(int size) : tree_(size + 1, 0) {}

    // A state is never removed after activation, so every affected Fenwick
    // node only needs to retain the largest DP value seen there.
    void update(int index, long long value) {
        while (index < static_cast<int>(tree_.size())) {
            tree_[index] = std::max(tree_[index], value);
            index += index & -index;
        }
    }

    // Return the best activated state whose original index is at most index.
    long long prefix_max(int index) const {
        long long result = 0;
        while (index > 0) {
            result = std::max(result, tree_[index]);
            index -= index & -index;
        }
        return result;
    }

private:
    std::vector<long long> tree_;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_count;
    if (!(std::cin >> test_count)) {
        return 0;
    }

    while (test_count-- > 0) {
        int n;
        std::cin >> n;

        std::vector<long long> weights(n);
        for (long long &weight : weights) {
            std::cin >> weight;
        }

        FenwickMax fenwick(n);

        // A tuple is (j + a[j], j, dp[j]). The min-heap delays each completed
        // state until it satisfies j + a[j] < the current index i.
        using Candidate = std::tuple<long long, int, long long>;
        std::priority_queue<Candidate, std::vector<Candidate>,
                            std::greater<Candidate>>
            pending;

        long long answer = 0;
        for (int index = 1; index <= n; ++index) {
            // If j immediately precedes i in the selected sequence, the pair
            // is compatible precisely when
            //
            //     j + a[j] < i  and  j < i - a[i].
            //
            // Activate all and only the states satisfying the first strict
            // inequality. A reach equal to index is still incompatible.
            while (!pending.empty() &&
                   std::get<0>(pending.top()) < static_cast<long long>(index)) {
                const auto [right_reach, old_index, old_dp] = pending.top();
                pending.pop();
                (void)right_reach;
                fenwick.update(old_index, old_dp);
            }

            // With integral indices, j < i - a[i] is equivalent to
            // j <= i - a[i] - 1. A non-positive prefix has no predecessor.
            const long long predecessor_limit =
                static_cast<long long>(index) - weights[index - 1] - 1;
            const long long best_predecessor = predecessor_limit > 0
                                                   ? fenwick.prefix_max(
                                                         static_cast<int>(
                                                             predecessor_limit))
                                                   : 0;
            const long long current_dp =
                best_predecessor + weights[index - 1];
            answer = std::max(answer, current_dp);

            pending.emplace(static_cast<long long>(index) + weights[index - 1],
                            index, current_dp);
        }

        // Consecutive selected pairs suffice: for non-consecutive endpoints,
        // the full distance exceeds both the first gap (which exceeds the left
        // weight) and the last gap (which exceeds the right weight). Therefore
        // dp[i] above considers exactly every valid extension ending at i.
        //
        // Every state has one heap push/pop and one Fenwick update/query, giving
        // O(n log n) time and O(n) space. The sum can reach 2 * 10^14, so weights
        // and DP values are stored in 64-bit long long integers.
        std::cout << answer << '\n';
    }

    return 0;
}
