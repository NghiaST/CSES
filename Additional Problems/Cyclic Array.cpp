#include <iostream>
#include <algorithm>
using namespace std;
long long n, k, a[400005];
int res, G[400005][20];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i], a[i] += a[i-1];
    for(int i=1; i<=n; ++i) a[i+n] = a[n] + a[i];
    for(int i=1; i<=n*2; ++i) G[i][0] = upper_bound(a+i, a+n*2, a[i-1] + k) - a;
    for(int j=1; j<20; ++j)
        for(int i=1; i<=n*2; ++i) G[i][j] = G[G[i][j-1]][j-1];
    res = n;
    for(int i=1; i<=n; ++i) {
        int w = i, seg = 1;
        for(int j=19; j>=0; --j) if (G[w][j] < i + n) w = G[w][j], seg += 1<<j;
        res = min(res, seg);
    }
    cout << res;
}
