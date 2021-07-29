#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int N = 200005;
int n, k, cL, cR, a[N], ans[N];
multiset<int> S;

void Enter() {
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
}

multiset<int>::iterator prv(multiset<int>::iterator p) { return --p; }

void Process() {
    S.insert(0);
    S.insert(1000000001);
    for(int i=1; i<=k; ++i) S.insert(a[i]);
    multiset<int>::iterator p = S.begin();
    for(int i=0; i<=(k-1)/2; ++i) ++p;
    cL = (k-1) / 2;
    cR = k / 2;
    ans[k] = *p;
    for(int i=k+1; i<=n; ++i) {
        if (a[i-k] == *p) {
            ++p;
            ++cL; --cR;
            S.erase(prv(p));
        }
        else S.erase(a[i-k]);
        S.insert(a[i]);
        if (a[i-k] <= *p) --cL; else --cR;
        if (a[i] < *p) ++cL; else ++cR;
        if (cL + 1 < cR) ++cL, --cR, ++p;
        if (cL > cR) --cL, ++cR, --p;
        ans[i] = *p;
    }
    for(int i=k; i<=n; ++i) cout << ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
