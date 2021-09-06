#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
int n, k;
long long res, f[1000005], f2[1000005], f3[1000005];
 
void Init() {
    f[0] = f[1] = f2[0] = f2[1] = f3[0] = f3[1] = 1;
    for(int i=2; i<=k; ++i) {
        f[i] = f[i-1] * i % MOD;
        f2[i] = MOD - MOD / i * f2[MOD % i] % MOD;
        f3[i] = f3[i-1] * f2[i] % MOD;
    }
}
 
long long power(int x, int i) {
    if (!i) return 1;
    long long w = power(x, i/2);
    (w *= w) %= MOD;
    if (i&1) (w *= x) %= MOD;
    return w;
}
 
long long C(int nn, int kk) {
    return f[nn] * f3[kk] % MOD * f3[nn - kk] % MOD;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    Init();
    for(int i=k, z=1; i; --i, z=-z)
        res = (res + power(i, n) * C(k, i) % MOD * z + MOD) % MOD;
    cout << res;
}
