#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
int n, r, Q[N], ans[N], ans2[N];
struct Data{
    int x, y, z;
    bool operator <  (Data &p) { return y < p.y || y == p.y && x > p.x; }
} a[N];
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].z = i;
    }
}
 
void Process() {
    sort(a+1, a+n+1);
    for(int i=1, maxr = 0; i<=n; ++i) {
        while (r && a[i].x <= a[Q[r]].x) ans[a[Q[r--]].z] = 1;
        if (maxr >= a[i].x) ans2[a[i].z] = 1;
        Q[++r] = i;
        maxr = max(maxr, a[i].x);
    }
    for(int i=1; i<=n; ++i) cout << ans2[i] << ' ';
    cout << '\n';
    for(int i=1; i<=n; ++i) cout << ans[i] << ' ';
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
