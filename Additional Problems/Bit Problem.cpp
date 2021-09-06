#include <iostream>
using namespace std;
int n, a[200005], f[1048576], f2[1048576];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], ++f[a[i]], ++f2[a[i]];
    for(int i=0; i<20; ++i)
    for(int j=0; j<1048576; ++j)
        if (!((j>>i)&1)) f[j^(1<<i)] += f[j];
    for(int i=0; i<20; ++i)
    for(int j=0; j<1048576; ++j)
        if ((j>>i)&1) f2[j^(1<<i)] += f2[j];
    for(int i=1; i<=n; ++i) cout << f[a[i]] << ' ' << f2[a[i]] << ' ' << n - f[1048575 ^ a[i]] << '\n';
}
