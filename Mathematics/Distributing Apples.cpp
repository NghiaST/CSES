#include <iostream>
using namespace std;
const int N = 2000005, MOD = 1e9 + 7;
long long n, m, f[N], f2[N], f3[N];
 
int main()
{
    f[0] = f[1] = f2[0] = f2[1] = f3[0] = f3[1] = 1;
    for(int i=2; i<=2000000; ++i) {
        f[i] = f[i-1] * i % MOD;
        f2[i] = MOD - MOD / i * f2[MOD % i] % MOD;
        f3[i] = f3[i-1] * f2[i] % MOD;
    }
    cin >> n >> m;
    cout << f[n + m - 1] * f3[m] % MOD * f3[n - 1] % MOD;
}
