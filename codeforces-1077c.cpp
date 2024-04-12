#include <bits/stdc++.h>
using namespace std;

struct Item {
    int idx;
    long long val;
    Item(int _idx = 0, long long _val = 0) : idx(_idx), val(_val) {};
    bool operator<(const Item &other) const { return val < other.val; }
};

void solve() {
    int n;
    cin >> n;
    vector<Item> items;
    long long sum = 0, val, tmp;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        sum += val;
        items.push_back(Item(i, val));
    }
    int len = items.size();
    sort(items.begin(), items.end());
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        tmp = sum - items[i].val;
        if (tmp % 2 != 0) continue;
        if (items[len - 1].idx == items[i].idx) {
            if (tmp / 2 == items[len - 2].val) ans.push_back(items[i].idx);
        } else if (tmp / 2 == items[len - 1].val) ans.push_back(items[i].idx);
    }
    if (ans.empty()) {
        cout << "0" << endl;
        return;
    }
    cout << ans.size() << endl;
    for (auto item: ans) cout << item + 1 << " ";
    cout << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
