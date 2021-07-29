#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n;
long long area, boundary;
struct point{ long long x, y; } a[N], tmp[N], Q[N];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
    a[0] = a[n]; a[n+1] = a[1];
    for(int i=1; i<=n; ++i) area += a[i].x * (a[i+1].y - a[i-1].y);
    area = abs(area);
    /// S = inside + boundary/2 - 1 => area = inside*2 + boundary - 2
    for(int i=1; i<=n; ++i) boundary += __gcd(abs(a[i].x - a[i-1].x), abs(a[i].y - a[i-1].y));
    cout << (area + 2 - boundary) / 2 << ' ' << boundary;
}
