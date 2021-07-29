#include <iostream>
#include <algorithm>
using namespace std;
const int N = 800005;
int n, q;
long long lazy_set[N], lazy_inc[N], sum[N];
string s;
 
void down_update(int l, int r, int pos) {
    int mid = (l+r) / 2;
    if (lazy_set[pos]) {
        lazy_set[pos*2] = lazy_set[pos*2+1] = lazy_set[pos]; lazy_set[pos] = 0;
        lazy_inc[pos*2] = lazy_inc[pos*2+1] = 0;
        sum[pos*2] = lazy_set[pos*2] * (mid-l+1);
        sum[pos*2+1] = lazy_set[pos*2+1] * (r-mid);
    }
    if (lazy_inc[pos]) {
        lazy_inc[pos*2] += lazy_inc[pos];
        lazy_inc[pos*2+1] += lazy_inc[pos];
        sum[pos*2] += lazy_inc[pos] * (mid-l+1);
        sum[pos*2+1] += lazy_inc[pos] * (r-mid);
        lazy_inc[pos] = 0;
    }
}
 
void update_inc(int l, int r, int x, int y, long long val, int pos) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        lazy_inc[pos] += val;
        sum[pos] += val * (r-l+1);
        return;
    }
    down_update(l, r, pos);
    int mid = (l+r) / 2;
    update_inc(l, mid, x, y, val, pos*2);
    update_inc(mid+1, r, x, y, val, pos*2+1);
    sum[pos] = sum[pos*2] + sum[pos*2+1];
}
 
void update_set(int l, int r, int x, int y, long long val, int pos) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        lazy_inc[pos] = 0;
        lazy_set[pos] = val;
        sum[pos] = val * (r-l+1);
        return;
    }
    down_update(l, r, pos);
    int mid = (l+r) / 2;
    update_set(l, mid, x, y, val, pos*2);
    update_set(mid+1, r, x, y, val, pos*2+1);
    sum[pos] = sum[pos*2] + sum[pos*2+1];
}
 
long long query(int l, int r, int x, int y, int pos) {
    if (l > y || r < x) return 0;
    if (x <= l && r <= y) return sum[pos];
    down_update(l, r, pos);
    int mid = (l+r) / 2;
    return query(l, mid, x, y, pos*2) + query(mid+1, r, x, y, pos*2+1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    int type, u, v, x;
    for(int i=1; i<=n; ++i) cin >> x, update_set(1, n, i, i, x, 1);
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> u >> v >> x;
            update_inc(1, n, u, v, x, 1);
        }
        else if (type == 2) {
            cin >> u >> v >> x;
            update_set(1, n, u, v, x, 1);
        }
        else {
            cin >> u >> v;
            cout << query(1, n, u, v, 1) << '\n';
        }
    }
}
