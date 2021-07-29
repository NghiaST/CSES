#include <iostream>
using namespace std;
int n, q, a[200005];
long long it[800009], lazy[800009];
 
void update(int l, int r, int x, int y, int val, int pos) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        lazy[pos] += val;
        it[pos] += val;
        return;
    }
    int mid = (l+r) / 2;
    update(l, mid, x, y, val, pos*2);
    update(mid+1, r, x, y, val, pos*2+1);
    it[pos] = max(it[pos*2], it[pos*2+1]) + lazy[pos];
}
 
long long query(int l, int r, int x, int y, int pos) {
    if (l > y || r < x) return -12345678987654321LL;
    if (x <= l && r <= y) return it[pos];
    int mid = (l+r) / 2;
    return max(query(l, mid, x, y, pos*2), query(mid+1, r, x, y, pos*2+1)) + lazy[pos];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        update(0, n, i, n, a[i], 1);
    }
    int type, u, v;
    while (q--) {
        cin >> type >> u >> v;
        if (type == 1) {
            update(0, n, u, n, v - a[u], 1);
            a[u] = v;
        }
        else cout << max(0ll, query(0, n, u, v, 1) - query(0, n, u-1, u-1, 1)) << '\n';
    }
}
