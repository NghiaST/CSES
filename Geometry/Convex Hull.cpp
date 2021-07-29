#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, r, r2;
long long res;
struct point{
    long long x, y;
    bool operator < (point &p) { return x < p.x || x == p.x && y < p.y; }
} a[N], Q[N], Q2[N];
 
long long acreage(point A, point B, point C) {
    return A.x * (C.y - B.y) + B.x * (A.y - C.y) + C.x * (B.y - A.y);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) {
        while (r > 1 && acreage(Q[r-1], Q[r], a[i]) < 0) --r;
        while (r2 > 1 && acreage(Q2[r2-1], Q2[r2], a[i]) > 0) --r2;
        Q[++r] = Q2[++r2] = a[i];
    }
    while (--r2 > 1) Q[++r] = Q2[r2];
    cout << r << '\n';
    for(int i=1; i<=r; ++i) cout << Q[i].x << ' ' << Q[i].y << '\n';
}
