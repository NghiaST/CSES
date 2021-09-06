#include <iostream>
#include <bitset>
using namespace std;
const int N = 100001;
int n, m, k, p[N], c[N];
bitset<100001> Q;
 
int DAD(int u) {
    if (p[u] < 0) return u;
    return p[u] = DAD(p[u]);
}
 
void Union(int u, int v) {
    int uu = DAD(u), vv = DAD(v);
    if (uu == vv) return;
    if (p[uu] < p[vv]) swap(uu, vv);
    p[uu] += p[vv];
    p[vv] = uu;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; ++i) p[i] = -1;
    int u, v;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v;
        Union(u, v);
    }
    Q[0] = 1;
    for(int i=1; i<=n; ++i) if (p[i] < 0) ++c[-p[i]];
    for(int i=1; i<=n; ++i) if (c[i] > 0) {
        int j = 1;
        while (j<<1 <= c[i]) {
            Q |= Q << (i * j);
            j <<= 1;
        }
        --j;
        Q |= Q << (i * (c[i] - j));
    }
    for(int i=1; i<=n; ++i) cout << Q[i];
}
