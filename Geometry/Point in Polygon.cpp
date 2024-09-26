#include <iostream>
using namespace std;
int n, q;
struct point {
    long long x, y;
    point operator - (point a) { return {x - a.x, y - a.y}; }
} a[1005];
 
long long cross(point a, point b) { return a.x * b.y - a.y * b.x; }
long long area(point a, point b, point c) { 
    long long w = cross(b - a, c - a);
    if (w < 0) return -1;
    else if (w > 0) return 1;
    else return 0;
}
 
int where_with_polygon(point w) {
    bool inside = false, touch = false;
    for(int i = 1; i <= n; ++i) {
        point p1 = a[i - 1], p2 = a[i];
        long long area1 = area(p1, p2, w);
        if (!area1 &&
            min(p1.x, p2.x) <= w.x && w.x <= max(p1.x, p2.x) &&
            min(p1.y, p2.y) <= w.y && w.y <= max(p1.y, p2.y)) 
            touch = true;
 
        if ((p1.y > w.y) != (p2.y > w.y) &&
            (((p2.y - p1.y) ^ area1) >> 63) == 0)
            inside = !inside;
    }
    if (touch) return -1;
    return inside;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
    a[0] = a[n];
    while (q--) {
        point w;
        cin >> w.x >> w.y;
        int ans = where_with_polygon(w);
        if (ans == -1) cout << "BOUNDARY\n";
        else if (ans == 0) cout << "OUTSIDE\n";
        else cout << "INSIDE\n";
    }
}