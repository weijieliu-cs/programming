#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        arr.push_back(num);
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (arr[i - 1] && arr[i + 1] && !arr[i])
            arr[i + 1] = 0, cnt++;
    }
    cout << cnt << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
