#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 200005;
int n, q, a[N], bit[N], ans[N];
map<int,int> M;
struct Data{
    int x, y, z;
    bool operator < (Data &p) { return y < p.y; };
} w[N];
 
void update(int x) {
    for(; x; x-=x&-x) ++bit[x];
}
 
int query(int x) {
    int val = 0;
    for(; x<=n; x+=x&-x) val += bit[x];
    return val;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> q;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=q; ++i) cin >> w[i].x >> w[i].y, w[i].z = i;
    sort(w+1, w+q+1);
    for(int i=1, l=1; i<=n; ++i) {
        update(M[a[i]]);
        M[a[i]] = i;
        while (l<=q && w[l].y == i) {
            ans[w[l].z] = w[l].y - w[l].x + 1 - query(w[l].x);
            ++l;
        }
    }
    for(int i=1; i<=q; ++i) cout << ans[i] << '\n';
}
