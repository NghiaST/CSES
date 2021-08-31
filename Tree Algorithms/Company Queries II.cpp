#include <iostream>
#include <vector>
using namespace std;
const int N = 200005;
int n, q, pa[N][20], h[N];
vector<int> S[N];
 
void Enter() {
    cin >> n >> q;
    int v;
    for(int i=2; i<=n; ++i) {
        cin >> v;
        S[v].push_back(i);
    }
    pa[1][0] = 1;
}
 
void DFS(int u) {
    for(int i=1; i<19; ++i) pa[u][i] = pa[pa[u][i-1]][i-1];
    for(int v : S[u]) {
        h[v] = h[u] + 1;
        pa[v][0] = u;
        DFS(v);
    }
}
 
int LCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int diff = h[u] - h[v];
    for(int i=18; i>=0; --i) if ((diff>>i)&1) u = pa[u][i];
    if (u == v) return u;
    for(int i=18; i>=0; --i) if (pa[u][i] != pa[v][i]) u = pa[u][i], v = pa[v][i];
    return pa[u][0];
}
 
void Process() {
    int u, v;
    while (q--) {
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    DFS(1);
    Process();
}
