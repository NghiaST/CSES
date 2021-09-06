#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int n, m;
long long res;
 
long long power(long long x, int k) {
    long long ans = 1;
    while (k > 0) {
        if (k & 1) (ans *= x) %= MOD;
        (x *= x) %= MOD;
        k >>= 1;
    }
    return ans;
}
 
int main()
{
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        res += power(m, __gcd(i, n));
    res %= MOD;
    res = res % MOD * power(n, MOD - 2) % MOD;
    cout << res;
}
