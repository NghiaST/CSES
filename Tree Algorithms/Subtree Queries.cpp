#include <iostream>
#include <vector>
using namespace std;
int n, q, cnt, a[200005], in[200005], out[200005], pp[200005];
long long it[800005];
vector<int> S[200005];
 
void visit(int u, int d) {
    in[u] = ++cnt, pp[cnt] = u;
    for(int v : S[u]) if (v != d)
        visit(v, u);
    out[u] = cnt;
}
 
void build(int l, int r, int pos) {
    if (l == r) return (void) (it[pos] = a[pp[l]]);
    int mid = (l+r) / 2;
    build(l, mid, pos*2);
    build(mid+1, r, pos*2+1);
    it[pos] = it[pos*2] + it[pos*2+1];
}
 
void update(int l, int r, int x, int val, int pos) {
    if (l == r) return (void) (it[pos] = val);
    int mid = (l+r) / 2;
    if (x <= mid) update(l, mid, x, val, pos*2);
    else update(mid+1, r, x, val, pos*2+1);
    it[pos] = it[pos*2] + it[pos*2+1];
}
 
long long query(int l, int r, int x, int y, int pos) {
    if (l > y || r < x) return 0;
    if (x <= l && r <= y) return it[pos];
    int mid = (l+r) / 2;
    return query(l, mid, x, y, pos*2) + query(mid+1, r, x, y, pos*2+1);
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
    build(1, n, 1);
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> u >> x;
            update(1, n, in[u], x, 1);
        }
        else {
            cin >> u;
            cout << query(1, n, in[u], out[u], 1) << '\n';
        }
    }
}
