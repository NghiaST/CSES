#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, q, rr, Q[N], a[N];
long long lazy[N*4], sum[N*4], ans[N];
struct Data{
    int x, y, z;
    bool operator < (Data &p) { return x < p.x; }
} w[N];
 
void update(int l, int r, int x, int y, long long val, int pos) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
        lazy[pos] += val;
        sum[pos] += val * (r-l+1);
        return;
    }
    int mid = (l+r) / 2;
    update(l, mid, x, y, val, pos*2);
    update(mid+1, r, x, y, val, pos*2+1);
    sum[pos] = sum[pos*2] + sum[pos*2+1] + lazy[pos] * (r-l+1);
}
 
long long query(int l, int r, int x, int y, long long LZ, int pos) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y) return sum[pos] + LZ * (r-l+1);
    LZ += lazy[pos];
    int mid = (l+r) / 2;
    return query(l, mid, x, y, LZ, pos*2) + query(mid+1, r, x, y, LZ, pos*2+1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=q; ++i) cin >> w[i].x >> w[i].y, w[i].z = i;
    sort(w+1, w+q+1);
    Q[0] = n + 1;
    for(int i=n, r=q; i; --i) {
        while (rr && a[Q[rr]] <= a[i]) {
            update(1, n, Q[rr], Q[rr-1] - 1, a[i] - a[Q[rr]], 1);
            --rr;
        }
        Q[++rr] = i;
        while (r && w[r].x == i) {
            ans[w[r].z] = query(1, n, w[r].x, w[r].y, 0, 1);
            --r;
        }
    }
    for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
}
