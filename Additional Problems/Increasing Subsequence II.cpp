#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005, MOD = 1e9 + 7;
int n, cnt, res, w, a[N], *b[N], bit[N];
 
void update(int x, int val) {
    for(; x<=cnt; x+=x&-x) (bit[x] += val) %= MOD;
}
 
int getBIT(int x) {
    int val = 1;
    for(--x; x; x-=x&-x) (val += bit[x]) %= MOD;
    return val;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], b[i] = &a[i];
    sort(b+1, b+n+1, [] (int *A, int *B) { return *A < *B; });
    for(int i=1, old; i<=n; ++i) {
        if (i == 1 || old != *b[i]) ++cnt, old = *b[i];
        *b[i] = cnt;
    }
    for(int i=1; i<=n; ++i) {
        w = getBIT(a[i]);
        update(a[i], w);
        res = (res + w) % MOD;
    }
    cout << res;
}
