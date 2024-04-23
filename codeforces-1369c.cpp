#include <bits/stdc++.h>
using namespace std;

bool compare(const int &a, const int &b) {
    return a > b;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> nums;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        nums.push_back(num);
    }
    int cnt = 0;
    vector<long long> tmp;
    for (int i = 0, num; i < k; ++i) {
        cin >> num;
        if (num == 1) {
            cnt++;
            continue;
        }
        tmp.push_back(num);
    }
    sort(nums.begin(), nums.end(), compare);
    sort(tmp.begin(), tmp.end(), compare);
    long long ans = 0;
    for (int i = 0; i < cnt; ++i) ans += nums[i] << 1;
    int left = cnt, right = nums.size() - 1, idx = 0;
    while (left <= right) {
        ans += nums[left] + nums[right];
        left++, right -= tmp[idx] - 1, idx++;
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
