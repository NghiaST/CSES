#include <iostream>
#define getBIT(x,i) ((x>>i)&1)
#define xorBIT(x,i) (x^(1<<i))
using namespace std;
const int MOD = 1e9 + 7;
long long n, m, c[20][20], f[1<<20][20];
 
int main()
{
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        ++c[--u][--v];
    }
    f[1][0] = 1;
    for(int i=0; i<n; ++i) f[(1<<i)^1][i] = c[0][i];
    for(int i=1; i<(1<<(n-1)); i+=2) {
        for(int j=1; j<n-1; ++j) if (getBIT(i,j))
            for(int w=1; w<n-1; ++w) if (getBIT(i,w))
                (f[i][j] += f[xorBIT(i,j)][w] * c[w][j]) %= MOD;
    }
    long long res = 0;
    for(int i=0; i<n-1; ++i)
        (res += f[(1<<(n-1))-1][i] * c[i][n-1]) %= MOD;
    cout << res;
}
