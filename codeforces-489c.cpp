#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m, s;
    cin >> m >> s;
    if (m == 1 && s < 10) {
        cout << s << " " << s << endl;
        return;
    }
    if (s > 9 * m || s == 0) {
        cout << "-1 -1" << endl;
        return;
    }
    // vector<int> ans(m, 0);
    vector<int> ans;
    while (s > 0) {
        int tmp = min(s, 9);
        ans.push_back(tmp);
        s -= tmp;
    }
    if (ans.size() == m) {
        for (auto it = ans.rbegin(); it != ans.rend(); ++it) cout << *it;
        cout << " ";
        for (auto it = ans.begin(); it != ans.end(); ++it) cout << *it;
        cout << endl;
    } else {
        cout << "1";
        for (int i = 0; i < m - 1 - ans.size(); ++i) cout << 0;
        cout << ans.back() - 1;
        for (int i = 0; i < ans.size() - 1; ++i) cout << 9;
        cout << " ";
        for (int i = 0; i < ans.size(); ++i) cout << ans[i];
        for (int i = 0; i < m - ans.size(); ++i) cout << 0;
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}