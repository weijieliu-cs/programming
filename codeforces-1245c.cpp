#include <bits/stdc++.h>
using namespace std;

long long fastPowerMod(long long base, long long exponent) {
    long long result = 1, modulus = 1e9 + 7;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % modulus;
        exponent >>= 1;
        base = (base * base) % modulus;
    }
    return result;
}

void solve() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'm' || str[i] == 'w') {
            cout << 0 << endl;
            return;
        }
    }
    long long modulus = 1e9 + 7;
    vector<long long> fib(str.size() + 5, 0);
    fib[0] = 1, fib[1] = 1, fib[2] = 2;
    for (int i = 3; i < fib.size(); ++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % modulus;
    str = str + '$';
    long long ans = 1, cnt = 1;
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == str[i - 1] && (str[i] == 'n' || str[i] == 'u')) cnt++;
        else {
            ans = (ans * fib[cnt]) % modulus;
            cnt = 1;
        }
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}