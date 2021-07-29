#include <iostream>
#include <algorithm>
using namespace std;
int n, k, res, a[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i=n, l=1; i>=l; --i) {
        if (a[i] + a[l] <= k) ++l;
        ++res;
    }
    cout << res;
}
