#include <iostream>
using namespace std;
const int N = 100005, MOD = 1e9 + 7, MOD2 = 1e9 + 6;
int n, a[N], b[N], c[N];
long long r1, r2, r3, w, pW;
 
long long power(long long x, long long k, long long MOD) {
    if (!k) return 1;
    long long w = power(x, k/2, MOD);
    (w *= w) %= MOD;
    if (k&1) (w *= x) %= MOD;
    return w;
}
 
int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i] >> b[i];
    r1 = 1;
    for(int i=1; i<=n; ++i) (r1 *= b[i] + 1) %= MOD;
    r2 = 1;
    for(int i=1; i<=n; ++i) (r2 *= (power(a[i], b[i] + 1, MOD) - 1) * power(a[i] - 1, MOD - 2, MOD) % MOD) %= MOD;
    w = pW = 1;
    int exist = 0;
    for(int i=1; i<=n; ++i) {
        if (!exist && b[i]&1) {
            exist = 1;
            (pW *= b[i]/2 + 1) %= MOD2;
        }
        else (pW *= b[i] + 1) %= MOD2;
    }
    if (!exist) {
        for(int i=1; i<=n; ++i) b[i] /= 2;
    }
    for(int i=1; i<=n; ++i) {
        (w *= power(a[i], b[i], MOD)) %= MOD;
    }
    r3 = power(w, pW, MOD);
    cout << r1 << ' ' << r2 << ' ' << r3;
}
