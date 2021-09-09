#include <iostream>
#include <algorithm>
const int MOD = 1e9 + 7;
int n, m, res, a[105];
long long f[2][55][10005];
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    f[0][0][5000] = 1;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<=50; ++j)
        for(int w=0; w<=10000; ++w) {
            (f[1][j][w] += (j + 1) * f[0][j][w]) %= MOD;
            if (j > 0 && w - a[i] >= 0) (f[1][j][w] += f[0][j - 1][w - a[i]]) %= MOD;
            if (j < 50 && w + a[i] <= 10000) (f[1][j][w] += (j + 1) * f[0][j + 1][w + a[i]]) %= MOD;
        }
        for(int j=0; j<=50; ++j)
        for(int w=0; w<=10000; ++w)
            f[0][j][w] = f[1][j][w], f[1][j][w] = 0;
    }
    for(int i=0; i<=m; ++i) (res += f[0][0][5000 - i]) %= MOD;
    cout << res;
}
