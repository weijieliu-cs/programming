#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &arr, int left, int val) {
    int right = arr.size() - 1;
    while (left <= right) {
        int middle = (left + right) >> 1;
        if (arr[middle] >= val)
            right = middle - 1;
        else left = middle + 1;
    }
    return right + 1;
}

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mmap;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        mmap[num]++;
    }
    vector<int> arr;
    for (auto item: mmap) arr.push_back(item.second);
    sort(arr.begin(), arr.end());
    int len = arr.size();
    int ans = arr[len - 1];
    for (int i = 1; i <= ans / 2; ++i) {
        int offset = 0, idx = -1;
        // Time limit exceeded on test 52
        // for (int item: arr) if (item >= i << offset) offset++;
        while (offset <= 18) {
            idx = binary_search(arr, idx + 1, i << offset);
            if (idx != len) offset++;
            else break;
        }
        ans = max(ans, (i << offset) - i);
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
