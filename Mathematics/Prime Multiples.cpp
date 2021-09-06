#include <iostream>
#include <algorithm>
using namespace std;
const long long INF = 2e18;
long long n, k, res, a[20], bit[1048576], f[1048576];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> k >> n;
    for(int i=0; i<n; ++i) cin >> a[i];
    f[0] = 1;
    for(int i=1; i<(1<<n); ++i) {
        bit[i] = bit[i/2] + (i&1);
        for(int j=0; j<n; ++j) if ((i>>j)&1) {
            if (INF / a[j] < f[i ^ (1<<j)]) f[i] = INF;
            else f[i] = f[i ^ (1<<j)] * a[j];
            break;
        }
        if (bit[i] & 1) res += k / f[i]; else res -= k / f[i];
    }
    cout << res;
}
