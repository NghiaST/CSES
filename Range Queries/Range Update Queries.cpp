#include <iostream>
#include <cmath>
using namespace std;
long long n, q, type, u, v, x, it[800005];
 
void update(int l, int r, int x, int y, int val, int pos) {
    if (l > y || r < x) return;
    if (x<=l && r<=y) {
        it[pos] += val;
        return;
    }
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
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> u, update(1, n, i, i, u, 1);
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> u >> v >> x;
            update(1, n, u, v, x, 1);
        }
        else {
            cin >> u;
            cout << query(1, n, u, 1) << '\n';
        }
    }
}
