#include <iostream>
#include <vector>
using namespace std;
int n, q, cnt, a[200005], in[200005], out[200005];
long long it[800005];
vector<int> S[200005];
 
void visit(int u, int d) {
    in[u] = ++cnt;
    for(int v : S[u]) if (v != d)
        visit(v, u);
    out[u] = cnt;
}
 
void update(int l, int r, int x, int y, int val, int pos) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) return (void) (it[pos] += val);
    int mid = (l+r) / 2;
    update(l, mid, x, y, val, pos*2);
    update(mid+1, r, x, y, val, pos*2+1);
}
 
long long query(int l, int r, int x, int pos) {
    if (l == r) return it[pos];
    int mid = (l+r) / 2;
    if (x <= mid) return query(l, mid, x, pos*2) + it[pos];
    else return query(mid+1, r, x, pos*2+1) + it[pos];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i];
    int type, u, v, x;
    for(int i=1; i<n; ++i) {
        cin >> u >> v;
        S[u].push_back(v);
        S[v].push_back(u);
    }
    visit(1, 0);
    for(int i=1; i<=n; ++i) update(1, n, in[i], out[i], a[i], 1);
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> u >> x;
            update(1, n, in[u], out[u], x - a[u], 1);
            a[u] = x;
        }
        else {
            cin >> u;
            cout << query(1, n, in[u], 1) << '\n';
        }
    }
}
