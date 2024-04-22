#include <bits/stdc++.h>
using namespace std;

long long helper(long long num) {
    if (num < 10) return num;
    long long tmp = num / 10 + 9, last = num % 10;
    while (num >= 10) num /= 10;
    if (num > last) tmp--;
    return tmp;
}

void solve() {
    long long l, r;
    cin >> l >> r;
    cout << helper(r) - helper(l - 1) << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}