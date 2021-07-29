#include <iostream>
using namespace std;
int n, q;
struct point{long long x, y;} a[1005];
const point INF_point = {0x3c3c3c3c, 0};
 
long long acreage(point A, point B, point C) {
    long long w = A.x * (C.y - B.y) + B.x * (A.y - C.y) + C.x * (B.y - A.y);
    if (w < 0) return -1;
    else if (w > 0) return 1;
    else return 0;
}
 
int Intersect(point a, point b, point c, point d) {
    long long area1 = acreage(a, b, c);
    long long area2 = acreage(a, b, d);
    long long area3 = acreage(c, d, a);
    long long area4 = acreage(c, d, b);
    if (!area1 && !area2) {
        if (min(a.x, b.x) > max(c.x, d.x) || min(c.x, d.x) > max(a.x, b.x) ||
            min(a.y, b.y) > max(c.y, d.y) || min(c.y, d.y) > max(a.y, b.y)) return 0;
        else return 1;
    }
    else if (area1 * area2 < 0 && area3 * area4 < 0) return 2;
    else return 0;
}
 
int where_with_polygon(point w) {
    for(int i=1; i<=n; ++i) if (!acreage(w, a[i-1], a[i])) {
        if (min(a[i-1].x, a[i].x) <= w.x && w.x <= max(a[i-1].x, a[i].x) &&
            min(a[i-1].y, a[i].y) <= w.y && w.y <= max(a[i-1].y, a[i].y))
            return 1;
    }
    int ret = 0;
    for(int i=1; i<=n; ++i) ret += Intersect(w, INF_point, a[i-1], a[i]);
    return (ret & 2);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
    point w;
    a[0] = a[n];
    while (q--) {
        cin >> w.x >> w.y;
        int ans = where_with_polygon(w);
        if (ans == 0) cout << "OUTSIDE\n";
        else if (ans == 1) cout << "BOUNDARY\n";
        else cout << "INSIDE\n";
    }
}
