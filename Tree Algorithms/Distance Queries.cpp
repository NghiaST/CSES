#include <iostream>
#include <vector>
using namespace std;
int n, q, pa[200005][20], h[200005];
vector<int> S[200005];
 
void visit(int u, int d) {
    pa[u][0] = d;
    h[u] = h[d] + 1;
    for(int v : S[u]) if (v != d)
        visit(v, u);
}
 
int LCA(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
    int diff = h[v] - h[u];
    for(int i=0; i<20; ++i)
        if ((diff>>i)&1) v = pa[v][i];
    for(int i=19; i>=0; --i) if (pa[u][i] != pa[v][i])
        u = pa[u][i], v = pa[v][i];
    if (u == v) return u;
    else return pa[u][0];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    int u, v;
    for(int i=1; i<n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    visit(1, 0);
    for(int i=1; i<20; ++i)
        for(int j=1; j<=n; ++j)
            pa[j][i] = pa[pa[j][i-1]][i-1];
    while (q--) {
        cin >> u >> v;
        cout << h[u] + h[v] - h[LCA(u, v)]*2 << '\n';
    }
}
