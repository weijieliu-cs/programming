#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    double tmp;
    for (int i = 0, num; i < n; ++i) {
        cin >> num >> tmp;
        arr.push_back(num);
    }
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] >= arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    cout << n - ans << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}