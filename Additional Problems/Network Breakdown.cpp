#include <iostream>
#include <map>
using namespace std;
const int N = 100005, M = 200005;
int n, m, k, res, dad[N], ans[M];
struct Data{ int u, v; } a[M], b[M];
map<int,int> Map[N];
 
int Find(int u) {
    if (dad[u] > 0) return dad[u] = Find(dad[u]);
    else return u;
}
 
void Union(int u, int v) {
    int uu = Find(u);
    int vv = Find(v);
    if (uu == vv) return;
    --res;
    if (dad[uu] < dad[vv]) swap(uu, vv);
    dad[uu] += dad[vv];
    dad[vv] = uu;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1; i<=m; ++i) cin >> a[i].u >> a[i].v;
    for(int i=1; i<=k; ++i) {
        cin >> b[i].u >> b[i].v;
        Map[b[i].u][b[i].v] = Map[b[i].v][b[i].u] = 1;
    }
    for(int i=1; i<=n; ++i) dad[i] = -1;
    res = n;
    for(int i=1; i<=m; ++i) {
        if (Map[a[i].u][a[i].v] == 0) Union(a[i].u, a[i].v);
    }
    for(int i=k; i; --i) {
        ans[i] = res;
        Union(b[i].u, b[i].v);
    }
    for(int i=1; i<=k; ++i) cout << ans[i] << ' ';
}
