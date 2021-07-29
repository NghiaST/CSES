#include <iostream>
using namespace std;
int n, q, w, ok, vs[200005], c[200005], val[200005], p[200005];
 
void DFS(int u) {
    if (val[u]) {
        w = val[u];
        return;
    }
    if (vs[u]) {
        val[u] = w -= c[u] - 1;
        ok = 1;
        return;
    }
    vs[u] = true;
    c[u] = ++w;
    DFS(p[u]);
 
    if (!ok) ++w;
    if (val[u]) ok = 0;
    val[u] = w;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> p[i];
    for(int i=1; i<=n; ++i) if (!val[i]) {
        w = 0;
        DFS(i);
    }
    for(int i=1; i<=n; ++i) cout << val[i] << ' ';
}
