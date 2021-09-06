#include <iostream>
using namespace std;
const int N = 2e5 + 5, maxF = 1e6 + 5;
int t, n, a[N], b[N], it[maxF * 4];
long long f[N];
 
long long get(int x, int val) {
    return f[x] + 1LL * b[x] * val;
}
 
long long query(int val, int l = 1, int r = 1000000, int pos = 1) {
    long long ans = get(it[pos], val);
    int mid = (l + r) / 2;
    if (l < r && val <= mid) ans = min(ans, query(val, l, mid, pos*2));
    if (l < r && mid < val) ans = min(ans, query(val, mid+1, r, pos*2+1));
    return ans;
}
 
void update(int id, int l = 1, int r = 1000000, int pos = 1) {
    if (l == r) {
        if (get(it[pos], l) >= get(id, l)) it[pos] = id;
        return;
    }
    int mid = (l+r) / 2;
    if (get(it[pos], l) <= get(id, l) && get(it[pos], r) <= get(id, r)) {
        return;
    }
    if (get(it[pos], l) >= get(id, l) && get(it[pos], r) >= get(id, r)) {
        it[pos] = id;
        return;
    }
    if (get(it[pos], l) <= get(id, l) && get(it[pos], mid) <= get(id, mid)) {
        update(id, mid + 1, r, pos * 2 + 1);
        return;
    }
    if (get(it[pos], l) >= get(id, l) && get(it[pos], mid) >= get(id, mid)) {
        update(it[pos], mid + 1, r, pos * 2 + 1);
        it[pos] = id;
    }
    if (get(it[pos], mid+1) <= get(id, mid+1) && get(it[pos], r) <= get(id, r)) {
        update(id, l, mid, pos * 2);
        return;
    }
    if (get(it[pos], mid+1) >= get(id, mid+1) && get(it[pos], r) >= get(id, r)) {
        update(it[pos], l, mid, pos * 2);
        it[pos] = id;
        return;
    }
    exit(1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> b[0];
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    for(int i=1; i<=n; ++i) {
        f[i] = query(a[i]);
        update(i);
    }
    cout << f[n];
}
