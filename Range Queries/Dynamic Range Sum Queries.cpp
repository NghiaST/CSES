#include <iostream>
#include <cmath>
using namespace std;
long long n, q, type, u, v, a[200005], bit[200005];
 
void update(int x, int val) {
    for(; x<=n; x+=x&-x) bit[x] += val;
}
 
long long getBIT(int x) {
    long long val = 0;
    for(; x; x-=x&-x) val += bit[x];
    return val;
}
 
int main()
{
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i], update(i, a[i]);
    while (q--) {
        cin >> type >> u >> v;
        if (type == 1) update(u, v - a[u]), a[u] = v;
        else cout << getBIT(v) - getBIT(u-1) << '\n';
    }
}
