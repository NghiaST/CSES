#include <iostream>
using namespace std;
const long long N = 1e6 + 5, MOD = 1e9 + 7;
int n, k;
long long ans, f[N], f2[N], f3[N];
string s;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> s;
    if (n % 2 == 1) return cout << 0, 0;
    for(char c : s) if (c == '(') ++k;
    else {
        if (--k < 0) return cout << 0, 0;
        n -= 2;
    }
    f[0] = f[1] = f2[0] = f2[1] = f3[0] = f3[1] = 1;
    for(int i=2; i<=n; ++i) {
        f[i] = f[i-1] * i % MOD;
        f2[i] = MOD - MOD / i * f2[MOD % i] % MOD;
        f3[i] = f3[i-1] * f2[i] % MOD;
    }
    n = n / 2 - k;
    /// n + k pair
    ans = f[n*2 + k] * f3[n] % MOD * f3[n + k] % MOD * (k + 1) % MOD * f2[n + k + 1] % MOD;
    cout << ans;
}
