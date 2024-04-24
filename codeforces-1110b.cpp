#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }
    int ans = arr.back() - arr[0] + 1;
    vector<int> diff;
    for (int i = 1; i < n; ++i)
        diff.push_back(arr[i] - arr[i - 1]);
    sort(diff.begin(), diff.end(), compare);
    for (int i = 0; i < k - 1; ++i)
        ans -= diff[i] - 1;
    cout << ans << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}