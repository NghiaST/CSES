#include <iostream>
using namespace std;
int n, q, it_l[800009], it_r[800009];
 
void update(int l, int r, int x, int val, int pos) {
    if (l == r) {
        it_l[pos] = val - l;
        it_r[pos] = val + l;
        return;
    }
    int mid = (l+r) / 2;
    if (x <= mid) update(l, mid, x, val, pos*2);
    else update(mid+1, r, x, val, pos*2+1);
    it_l[pos] = min(it_l[pos*2], it_l[pos*2+1]);
    it_r[pos] = min(it_r[pos*2], it_r[pos*2+1]);
}
 
int query_l(int l, int r, int x, int y, int pos) {
    if (l > y || r < x) return 0x3c3c3c3c;
    if (x <= l && r <= y) return it_l[pos];
    int mid = (l+r) / 2;
    return min(query_l(l, mid, x, y, pos*2), query_l(mid+1, r, x, y, pos*2+1));
}
 
int query_r(int l, int r, int x, int y, int pos) {
    if (l > y || r < x) return 0x3c3c3c3c;
    if (x <= l && r <= y) return it_r[pos];
    int mid = (l+r) / 2;
    return min(query_r(l, mid, x, y, pos*2), query_r(mid+1, r, x, y, pos*2+1));
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    int x;
    for(int i=1; i<=n; ++i) {
        cin >> x;
        update(1, n, i, x, 1);
    }
    int type, u, v;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            update(1, n, u, v, 1);
        }
        else {
            cin >> u;
            cout << min(query_l(1, n, 1, u, 1) + u, query_r(1, n, u, n, 1) - u) << '\n';
        }
    }
}
