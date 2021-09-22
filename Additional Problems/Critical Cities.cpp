/// Dominator Tree
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 5;
int n, m, cnt;
int arr[N], rev[N];
int sdom[N], dom[N], parent[N], dsu[N], label[N];
int Ans[N], res;
vector<int> S[N], S2[N], bucket[N], Tree[N];
 
void DFS(int u) {
    ++cnt; arr[u] = cnt; rev[cnt] = u;
    sdom[cnt] = label[cnt] = dsu[cnt] = cnt;
    for(int v : S[u]) {
        if (!arr[v]) {
            DFS(v);
            parent[arr[v]] = arr[u];
        }
        S2[arr[v]].push_back(arr[u]);
    }
}
 
int Find(int u, int x = 0) {
    if (u == dsu[u]) return x ? -1 : u;
    int v = Find(dsu[u], x+1);
    if (v < 0) return u;
    if (sdom[label[dsu[u]]] < sdom[label[u]])
        label[u] = label[dsu[u]];
    dsu[u] = v;
    return x ? v : label[u];
}
 
void Union(int u, int v) {
    dsu[v] = u;
}
 
bool DFS2(int u, int pa = 0) {
    if (u == n) {
        Ans[u] = true;
        return true;
    }
    for(int v : Tree[u])
    if (v != pa && DFS2(v, u)) {
        Ans[u] = true;
        return true;
    }
    return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        int u, v;
        cin >> u >> v;
        S[u].push_back(v);
    }
    DFS(1);
 
    for(int i=n; i; --i) {
        for(int v : S2[i])
            sdom[i] = min(sdom[i], sdom[Find(v)]);
        if (i > 1) bucket[sdom[i]].push_back(i);
        for(int w : bucket[i]) {
            int v = Find(w);
            if (sdom[v] == sdom[w]) dom[w] = sdom[w];
            else dom[w] = v;
        }
        if (i > 1) Union(parent[i], i);
    }
 
    for(int i=2; i<=n; ++i) {
        if (dom[i] != sdom[i]) dom[i] = dom[dom[i]];
        Tree[rev[i]].push_back(rev[dom[i]]);
        Tree[rev[dom[i]]].push_back(rev[i]);
    }
    DFS2(1);
    for(int i=1; i<=n; ++i) if (Ans[i]) ++res;
    cout << res << '\n';
    for(int i=1; i<=n; ++i) if (Ans[i]) cout << i << ' ';
}
