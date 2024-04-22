#include <bits/stdc++.h>
using namespace std;

struct Node {
    int a, b;
    Node(int _a = 0, int _b = 0) : a(_a), b(_b) {}
    bool operator<(const Node &other) const {
        if (a != other.a)
            return a < other.a;
        return b < other.b;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Node> arr;
    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        arr.emplace_back(a, b);
    }
    sort(arr.begin(), arr.end());
    int ans = arr[0].b;
    for (int i = 1; i < arr.size(); ++i) {
        ans = arr[i].b >= ans ? arr[i].b : arr[i].a;
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}