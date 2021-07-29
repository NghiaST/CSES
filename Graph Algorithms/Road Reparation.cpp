#include <iostream>
#include <algorithm>
using namespace std;
int n, m, pa[100005];
long long res;
struct Data{
    int x, y, z;
    bool operator < (Data &p) { return z < p.z; }
} a[200005];
 
void Enter() {
    cin >> n >> m;
    for(int i=1; i<=m; ++i) cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a+1, a+m+1);
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
    for(int i=1; i<=n; ++i) pa[i] = -1;
    for(int i=1; i<=m; ++i) {
        int u = DAD(a[i].x), v = DAD(a[i].y);
        if (u == v) continue;
        res += a[i].z;
        if (Union(u, v) == n) {
            cout << res;
            exit(0);
        }
    }
    cout << "IMPOSSIBLE";
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    Enter();
    Process();
}
