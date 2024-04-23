#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> &arr1, vector<long long> &arr2, long long mid) {
    long long tmp = 0;
    for (int i = 0; i < arr1.size(); ++i)
        if (arr1[i] > mid) tmp += arr2[i];
    return tmp <= mid;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> arr1(n, 0), arr2(n, 0);
    long long tmax = -1;
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
        tmax = max(tmax, arr1[i]);
    }
    for (int i = 0; i < n; ++i) cin >> arr2[i];
    long long left = 1, right = tmax, middle;
    while (left <= right) {
        middle = (left + right) >> 1;
        if (check(arr1, arr2, middle))
            right = middle - 1;
        else left = middle + 1;
    }
    // what's the difference between `left` and `right`?
    // cout << right << endl;
    cout << left << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
