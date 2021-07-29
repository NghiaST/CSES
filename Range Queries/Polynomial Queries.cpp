#include <iostream>
using namespace std;
const int N = 800005;
int n, q;
long long a[N], lazy_add[N], lazy_cnt[N], sum[N];
 
void update(int l, int r, int x, int y, int val, int pos) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        lazy_add[pos] += val;
        ++lazy_cnt[pos];
        sum[pos] += 1LL * (r-l+1) * (r+l) / 2 - 1LL * (r-l+1) * val;
        return;
    }
    int mid = (l+r) / 2;
    update(l, mid, x, y, val, pos*2);
    update(mid+1, r, x, y, val, pos*2+1);
    sum[pos] = sum[pos*2] + sum[pos*2+1] + 1LL * (r-l+1) * (r+l) / 2 * lazy_cnt[pos] - 1LL * (r-l+1) * lazy_add[pos];
}
 
long long query(int l, int r, int x, int y, long long LZ_add, long long LZ_cnt, int pos) {
    if (l > y || r < x) return 0;
    if (x <= l && r <= y) return sum[pos] + 1LL * (r-l+1) * (r+l) / 2 * LZ_cnt - 1LL * (r-l+1) * LZ_add;
    int mid = (l+r) / 2;
    LZ_add += lazy_add[pos];
    LZ_cnt += lazy_cnt[pos];
    return query(l, mid, x, y, LZ_add, LZ_cnt, pos*2) + query(mid+1, r, x, y, LZ_add, LZ_cnt, pos*2+1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    int type, x, y;
    for(int i=1; i<=n; ++i) cin >> a[i], a[i] += a[i-1];
    while (q--) {
        cin >> type >> x >> y;
        if (type == 1) update(1, n, x, y, x-1, 1);
        else cout << a[y] - a[x-1] + query(1, n, x, y, 0, 0, 1) << '\n';
    }
}
