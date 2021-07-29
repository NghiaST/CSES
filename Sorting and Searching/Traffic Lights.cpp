#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, x, res, a[200005], ans[200005];
set<int> S;
typedef set<int>::iterator sii;
 
sii prv(sii p) { return --p; }
sii nxt(sii p) { return ++p; }
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> x >> n;
    for(int i=1; i<=n; ++i) cin >> a[i], S.insert(a[i]);
    S.insert(0);
    S.insert(x);
    int w = 0;
    for(sii i = ++S.begin(); i != S.end(); ++i) {
        res = max(res, *i - w);
        w = *i;
    }
    for(int i=n; i; --i) {
        ans[i] = res;
        sii p = S.lower_bound(a[i]);
        sii pl = prv(p);
        sii pr = nxt(p);
        res = max(res, *pr - *pl);
        S.erase(p);
    }
    for(int i=1; i<=n; ++i) cout << ans[i] << ' ';
}
