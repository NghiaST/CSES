#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, n2, m, q, cnt, num[N], low[N], h[N], p[N][18];
vector<int> Q, S[N], S2[N];
 
void BCC(int u, int pa) {
    num[u] = low[u] = ++cnt;
    Q.push_back(u);
    for(int v : S[u]) if (v != pa) {
        if (num[v]) low[u] = min(low[u], num[v]);
        else {
            BCC(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if (pa && low[u] >= num[pa]) {
        S2[pa].push_back(++n2);
        int v;
        do {
            v = Q.back(); Q.pop_back();
            S2[n2].push_back(v);
        } while (v != u);
    }
}
 
void DFS(int u) {
    for(int i=1; i<18; ++i) p[u][i] = p[p[u][i-1]][i-1];
    for(int v : S2[u]) {
        h[v] = h[u] + 1;
        p[v][0] = u;
        DFS(v);
    }
}
 
int LCA(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
    for(int i=17; i>=0; --i) if (h[p[v][i]] >= h[u]) v = p[v][i];
    if (u == v) return u;
    for(int i=17; i>=0; --i) if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
    return p[u][0];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> q; n2 = n;
    for(int i=1; i<=m; ++i) {
        int u, v;
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    BCC(1, 0);
    h[1] = 1; DFS(1);
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = LCA(a, b), y = LCA(a, c), z = LCA(b, c);
        if (x == y && z == c || x == z && y == c) cout << "NO\n";
        else cout << "YES\n";
    }
}
