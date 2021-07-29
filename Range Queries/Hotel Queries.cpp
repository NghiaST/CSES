#include <iostream>
using namespace std;
int n, q, x, it[800005];
 
void update(int l, int r, int x, int val, int pos) {
    if (l == r) return (void) (it[pos] = val);
    int mid = (l+r) / 2;
    if (x <= mid) update(l, mid, x, val, pos*2);
    else update(mid+1, r, x, val, pos*2+1);
    it[pos] = max(it[pos*2], it[pos*2+1]);
}
 
void query(int l, int r, int cnt, int pos) {
    if (l == r) {
        if (it[pos] >= cnt) {
            it[pos] -= cnt;
            cout << l << ' ';
        }
        else cout << "0 ";
        return;
    }
    int mid = (l+r) / 2;
    if (it[pos*2] >= cnt) query(l, mid, cnt, pos*2);
    else query(mid+1, r, cnt, pos*2+1);
    it[pos] = max(it[pos*2], it[pos*2+1]);
}
 
int main()
{
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> x, update(1, n, i, x, 1);
    while (q--) {
        cin >> x;
        query(1, n, x, 1);
    }
}
