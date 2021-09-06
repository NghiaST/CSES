#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, res;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(long long i=1; i*i<=n; ++i) {
        long long w = max(n/i, i-1);
        res = res + (w - i + 1) % MOD * i % MOD + (w - i + 1) % MOD * ((w + i) % MOD) % MOD * ((MOD + 1) / 2) % MOD;
        res = (res + MOD - i) % MOD;
    }
    cout << res;
}
