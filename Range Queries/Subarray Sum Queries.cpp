#include <iostream>
using namespace std;
const int N = 800009;
int n, q;
long long a[N], it_min[N], it_max[N], ans[N], lazy[N];
 
void update(int l, int r, int x, int y, int val, int pos) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        lazy[pos] += val;
        it_min[pos] += val;
        it_max[pos] += val;
        return;
    }
    int mid = (l+r) / 2;
    update(l, mid, x, y, val, pos*2);
    update(mid+1, r, x, y, val, pos*2+1);
 
    ans[pos] = max(ans[pos*2], ans[pos*2+1]);
    ans[pos] = max(ans[pos], it_max[pos*2+1] - it_min[pos*2]);
    it_min[pos] = min(it_min[pos*2], it_min[pos*2+1]) + lazy[pos];
    it_max[pos] = max(it_max[pos*2], it_max[pos*2+1]) + lazy[pos];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        update(0, n, i, n, a[i], 1);
    }
    int u, x;
    while (q--) {
        cin >> u >> x;
        update(0, n, u, n, x - a[u], 1);
        a[u] = x;
        cout << ans[1] << '\n';
    }
}
