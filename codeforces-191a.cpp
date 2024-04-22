#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(30, vector<int>(30, 0));
    string str;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        int a = str[0] - 'a';
        int b = str.back() - 'a';
        int len = str.size();
        for (int j = 0; j < 26; ++j)
            if (dp[j][a] != 0) dp[j][b] = max(dp[j][b], dp[j][a] + len);
        // dp[j][b] = max(dp[j][b], dp[j][a] + str.size()); ERROR
        dp[a][b] = max(dp[a][b], len);
    }
    int ans = -1;
    for (int i = 0; i < 26; ++i) ans = max(ans, dp[i][i]);
    cout << ans << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}