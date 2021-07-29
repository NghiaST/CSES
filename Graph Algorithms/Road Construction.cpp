#include <iostream>
#include <algorithm>
using namespace std;
int n, m, pa[100005];
 
void Enter() {
    cin >> n >> m;
}
 
int DAD(int u) {
    if (pa[u] > 0) return pa[u] = DAD(pa[u]);
    else return u;
}
 
int Union(int u, int v) {
    if (pa[u] < pa[v]) swap(u, v);
    pa[u] += pa[v];
    pa[v] = u;
    return -pa[u];
}
 
void Process() {
    int res = n, maxs = 1;
    for(int i=1; i<=n; ++i) pa[i] = -1;
    int x, y, u, v;
    for(int i=1; i<=m; ++i) {
        cin >> x >> y;
        u = DAD(x), v = DAD(y);
        if (u != v) {
            --res;
            maxs = max(maxs, Union(u, v));
        }
        cout << res << ' ' << maxs << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    Enter();
    Process();
}
