#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, c[200005], a[200005], h[200005], pa[200005][20];
vector<int> S[200005];
map<int,int> color;
 
int LCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int diff = h[u] - h[v];
    for(int i=0; i<20; ++i) if ((diff>>i)&1) u = pa[u][i];
    for(int i=19; i>=0; --i)
        if (pa[u][i] != pa[v][i]) u = pa[u][i], v = pa[v][i];
    if (u == v) return u;
    return pa[u][0];
}
 
void visit(int u, int d) {
    h[u] = h[d] + 1;
    pa[u][0] = d;
    for(int i=1; i<20; ++i)
        pa[u][i] = pa[pa[u][i-1]][i-1];
    if (color[a[u]]) --c[LCA(u, color[a[u]])];
    color[a[u]] = u;
    for(int v : S[u]) if (v != d)
        visit(v, u);
    ++c[u];
    c[d] += c[u];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    int type, u, v, x;
    for(int i=1; i<n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    visit(1, 0);
    for(int i=1; i<=n; ++i) cout << c[i] << ' ';
}
