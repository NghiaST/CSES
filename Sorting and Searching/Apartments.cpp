#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, res, a[200005], b[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=m; ++i) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    for(int i=1, l=1; i<=n; ++i) {
        while (l <= m && b[l] < a[i] - k) ++l;
        if (l > m) break;
        if (b[l] <= a[i] + k) ++res, ++l;
    }
    cout << res;
}
