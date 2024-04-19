#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(1e5 + 5, 0);
    int tmax = -1;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        arr[num]++;
        tmax = max(tmax, num);
    }
    vector<long long> dp(1e5 + 5, 0);
    dp[1] = arr[1];
    for (int i = 2; i <= tmax; ++i)
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i] * i);
    cout << dp[tmax] << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}