#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
int n, k;
long long res, f[1005][1005];
 
long long len(int x) {
    if (x & 1) return x / 4 * 2 + 1;
    else return (x-1) / 4 * 2 + 2;
}
 
int main()
{
    cin >> n >> k;
    if (k >= n*2) {
        cout << 0;
        return 0;
    }
    for(int i=0; i<n*2; ++i) f[i][0] = 1;
    f[1][1] = 1;
    for(int i=2; i<n*2; ++i)
    for(int j=1; j<=k; ++j)
        f[i][j] = (f[i-2][j] + f[i-2][j-1] * (len(i) - j + 1)) % MOD;
    for(int i=0; i<=k; ++i) (res += f[n*2-1][i] * f[n*2-2][k-i]) %= MOD;
    cout << res;
}
