#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;
int t;
struct point{long long x, y;} a, b, c, d;
 
long long acreage(point A, point B, point C) {
    long long w = A.x * (C.y - B.y) + B.x * (A.y - C.y) + C.x * (B.y - A.y);
    if (w < 0) return -1;
    else if (w > 0) return 1;
    else return 0;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        long long area1 = acreage(a, b, c);
        long long area2 = acreage(a, b, d);
        long long area3 = acreage(c, d, a);
        long long area4 = acreage(c, d, b);
        if (!area1 && !area2) {
            if (min(a.x, b.x) > max(c.x, d.x) || min(c.x, d.x) > max(a.x, b.x) ||
                min(a.y, b.y) > max(c.y, d.y) || min(c.y, d.y) > max(a.y, b.y)) cout << "NO\n";
            else cout << "YES\n";
        }
        else if (area1 * area2 <= 0 && area3 * area4 <= 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
