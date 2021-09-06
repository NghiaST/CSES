#include <iostream>
using namespace std;
const int N = 105, MOD = 1e9 + 7;
int n, m, k;
struct matrix{
    long long x[N][N];
    matrix operator * (const matrix &p) {
        matrix C;
        for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j) {
            C.x[i][j] = 0;
            for(int w=0; w<n; ++w) C.x[i][j] = (C.x[i][j] + x[i][w] * p.x[w][j]) % MOD;
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
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        ++root.x[--u][--v];
    }
    matrix ans = get(k);
    cout << ans.x[0][n-1];
}
