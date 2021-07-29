#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long res;
int a[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i=1; i*2<=n; ++i) res += a[n-i+1] - a[i];
    cout << res;
}
