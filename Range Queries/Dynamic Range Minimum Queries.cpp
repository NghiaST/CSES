#include <iostream>
#include <cmath>
using namespace std;
int n, q, type, u, v, it[800005];
 
void update(int l, int r, int x, int val, int pos) {
    if (l == r) return (void) (it[pos] = val);
    int mid = (l+r) / 2;
    if (x <= mid) update(l, mid, x, val, pos*2);
    else update(mid+1, r, x, val, pos*2+1);
    it[pos] = min(it[pos*2], it[pos*2+1]);
}
 
int query(int l, int r, int x, int y, int pos) {
    if (l > y || r < x) return 0x3c3c3c3c;
    if (x<=l && r<=y) return it[pos];
    int mid = (l+r) / 2;
    return min(query(l, mid, x, y, pos*2), query(mid+1, r, x, y, pos*2+1));
}
 
int main()
{
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> u, update(1, n, i, u, 1);
    while (q--) {
        cin >> type >> u >> v;
        if (type == 1) update(1, n, u, v, 1);
        else cout << query(1, n, u, v, 1) << '\n';
    }
}
