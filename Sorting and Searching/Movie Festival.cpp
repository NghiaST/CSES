#include <iostream>
#include <algorithm>
using namespace std;
int n, b[200005], f[200005];
struct Data{
    int x, y;
    bool operator < (Data &p) { return y < p.y; }
} a[200005];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) {
        f[i] = max(f[i-1], f[upper_bound(b+1, b+i, a[i].x) - b - 1] + 1);
        b[i] = a[i].y;
    }
    cout << f[n];
}
