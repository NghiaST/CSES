#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, ans[N], bit[N];
struct Data{
    int x, y;
    bool operator < (Data &p) { return x < p.x || x == p.x && y > p.y; }
} a[N];
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x, a[i].y = i;
}
 
int getBIT(int x) {
    int val = 0;
    for(; x; x-=x&-x) val = max(val, bit[x]);
    return val;
}
 
void update(int x) {
    for(int p=x; x<=n; x+=x&-x) bit[x] = max(bit[x], p);
}
 
void Process() {
    sort(a+1, a+n+1);
    for(int i=1; i<=n; ++i) {
        ans[a[i].y] = getBIT(a[i].y);
        update(a[i].y);
    }
    for(int i=1; i<=n; ++i) cout << ans[i] << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
