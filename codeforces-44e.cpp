#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, a, b;
    cin >> k >> a >> b;
    string str;
    cin >> str;
    int len = str.size();
    if (len < k * a || len > k * b) {
        cout << "No solution" << endl;
        return;
    }
    int idx = 0;
    for (int i = 0; i < len % k; ++i) {
        for (int j = 0; j < (len / k + 1); ++j)
            cout << str[idx++];
        cout << endl;
    }
    for (int i = 0; i < k - len % k; ++i) {
        for (int j = 0; j < len / k; ++j)
            cout << str[idx++];
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
