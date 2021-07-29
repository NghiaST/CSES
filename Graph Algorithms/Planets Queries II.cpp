#include <iostream>
using namespace std;
int n, q, vs[200005], h[200005], p[200005][20];
 
void DFS(int u) {
    if (vs[u]) return;
    vs[u] = true;
    DFS(p[u][0]);
    h[u] = h[p[u][0]] + 1;
}
 
int get(int u, int high) {
    if (high < 0) return 0;
    for(int i=0; i<20; ++i)
        if (high >> i & 1) u = p[u][i];
    return u;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> p[i][0];
    for(int i=1; i<20; ++i)
        for(int j=1; j<=n; ++j)
            p[j][i] = p[p[j][i-1]][i-1];
    for(int i=1; i<=n; ++i)
        if (!h[i]) DFS(i);
    int u, v, x;
    while (q--) {
        cin >> u >> v;
        x = get(u, h[u]);
        if (get(u, h[u] - h[v]) == v) cout << h[u] - h[v] << '\n';
        else if (get(x, h[x] - h[v]) == v) cout << h[x] - h[v] + h[u] << '\n';
        else cout << "-1\n";
    }
}
