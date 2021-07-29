#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n;
long long res = 8e18;
struct point{ long long x, y; } a[N], tmp[N], Q[N];
bool cmp1(point a, point b) { return a.x < b.x || a.x == b.x && a.y < b.y; }
bool cmp2(point a, point b) { return a.y < b.y || a.y == b.y && a.x < b.x; }
 
long long range(point a, point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
 
void getMin(int l, int r) {
    if (l == r) return;
    int mid = (l+r) / 2;
    long long x_mid = a[mid].x;
    getMin(l, mid);
    getMin(mid+1, r);
    merge(a+l, a+mid, a+mid, a+r+1, tmp, cmp2);
    copy(tmp, tmp+r-l+1, a+l);
    int rr = 0;
    for(int i=l; i<=r; ++i) if ((a[i].x - x_mid) * (a[i].x - x_mid) <= res) Q[++rr] = a[i];
    for(int i=1; i<=rr; ++i)
        for(int j=i+1; j<=rr && j<=i+7; ++j) res = min(res, range(Q[i], Q[j]));
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].y;
    sort(a+1, a+n+1, cmp1);
    getMin(1, n);
    cout << res;
}
