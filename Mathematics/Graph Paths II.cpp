#include <iostream>
using namespace std;
const long long N = 105, MOD = 1e9 + 7, INF = 0x3c3c3c3cLL * 0x3c3c3c3cLL;
int n, m, k;
struct matrix{
    long long x[N][N];
    matrix operator * (const matrix &p) {
        matrix C;
        for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j) {
            C.x[i][j] = INF;
            for(int w=0; w<n; ++w) C.x[i][j] = min(C.x[i][j], x[i][w] + p.x[w][j]);
        }
        return C;
    }
} root;
 
matrix get(long long w) {
    if (w == 1) return root;
    matrix p = get(w / 2);
    p = p * p;
    if (w&1) p = p * root;
    return p;
}
 
int main()
{
    cin >> n >> m >> k;
    long long u, v, w;
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) root.x[i][j] = INF;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v >> w;
        --u; --v;
        root.x[u][v] = min(root.x[u][v], w);
    }
    long long ans = get(k).x[0][n-1];
    if (ans == INF) ans = -1;
    cout << ans;
}
