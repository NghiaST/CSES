#include <iostream>
using namespace std;
int n;
long long res;
struct point{long long x, y;} a[1005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
    a[0] = a[n]; a[n+1] = a[1];
    for(int i=1; i<=n; ++i) res += a[i].x * (a[i+1].y - a[i-1].y);
    cout << abs(res);
}
