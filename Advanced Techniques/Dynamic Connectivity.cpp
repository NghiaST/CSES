#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int N = 100005;
int n, m, k, TPLT;
int sz[N], dad[N], Ans[N];
vector<pair<int,int>> Q[N * 4], Save[N * 4];
map<pair<int,int>, int> Map;
 
int Find(int u) {
    if (dad[u]) return Find(dad[u]);
    return u;
}
 
void Union(int u, int v, int pos) {
    u = Find(u); v = Find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    --TPLT;
    sz[u] += sz[v];
    dad[v] = u;
    Save[pos].emplace_back(u, v);
}
 
void Decomposition(int u, int v) {
    ++TPLT;
    sz[u] -= sz[v];
    dad[v] = 0;
}
 
void update(pair<int,int> edge, int x, int y, int l = 0, int r = k, int pos = 1) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
        Q[pos].push_back(edge);
        return;
    }
    int mid = (l+r) / 2;
    update(edge, x, y, l, mid, pos*2);
    update(edge, x, y, mid+1, r, pos*2+1);
}
 
void query(int l, int r, int pos) {
    for(pair<int,int> edge : Q[pos])
        Union(edge.first, edge.second, pos);
    if (l == r) Ans[l] = TPLT;
    else {
        int mid = (l+r) / 2;
        query(l, mid, pos*2);
        query(mid+1, r, pos*2+1);
    }
    for(int i = Save[pos].size() - 1; i >= 0; --i) Decomposition(Save[pos][i].first, Save[pos][i].second);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> k;
    int type, u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        Map[{u, v}] = 0;
    }
    for(int i=1; i<=k; ++i) {
        cin >> type >> u >> v;
        if (u > v) swap(u, v);
        if (type == 1) Map[{u, v}] = i;
        else {
            update({u, v}, Map[{u, v}], i-1);
            Map.erase(Map.find({u, v}));
        }
    }
    for(pair<pair<int,int>,int> x : Map)
        update(x.first, x.second, k);
    TPLT = n;
    for(int i=1; i<=n; ++i) sz[i] = 1;
    query(0, k, 1);
    for(int i=0; i<=k; ++i) cout << Ans[i] << ' ';
}
