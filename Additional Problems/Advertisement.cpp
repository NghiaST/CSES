#include <iostream>
using namespace std;
long long n, r, res, a[200005], Q[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) {
        while (r && a[Q[r]] >= a[i]) {
            res = max(res, (i - 1 - Q[r-1]) * a[Q[r]]);
            --r;
        }
        Q[++r] = i;
    }
    while (r) {
        res = max(res, (n - Q[r-1]) * a[Q[r]]);
        --r;
    }
    cout << res;
}
