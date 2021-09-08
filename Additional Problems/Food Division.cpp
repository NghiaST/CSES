#include <iostream>
#include <algorithm>
using namespace std;
long long n, x, a[200005];
long long res;
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> x, a[i] += a[i-1] - x;
    sort(a+1, a+n+1);
    for(int i=1; i*2<=n; ++i) res += a[n - i + 1] - a[i];
    cout << res;
}
