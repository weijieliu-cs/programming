#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

void solve() {
    int n;
    cin >> n;
    // ERROR: vector<long long> cnt(n, 0);
    vector<long long> cnt(n + 5, 0);
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        cnt[num]++;
    }
    vector<long long> arr;
    // ERROR: for (int i = 0; i < n; ++i)
    for (int i = 0; i < cnt.size(); ++i)
        if (cnt[i] != 0) arr.push_back(cnt[i]);
    sort(arr.begin(), arr.end(), compare);
    long long ans = arr[0], tmp = arr[0] - 1;
    for (int i = 1; i < arr.size(); ++i) {
        if (tmp == 0) break;
        tmp = min(tmp, arr[i]);
        ans += tmp;  // maintain a variable `tmp`
        tmp--;
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
