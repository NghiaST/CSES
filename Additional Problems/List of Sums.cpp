#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, p, a[10005], b[105];
multiset<int> S;
 
void add(int x) {
    b[++p] = x;
    for(int i=1; i<p; ++i) S.insert(b[i] + x);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n*(n-1)/2; ++i) cin >> a[i];
    sort(a+1, a+n*(n-1)/2+1);
    for(int i=3; i<=n; ++i) {
        long long w = a[1] + a[2] + a[i];
        if (w & 1) continue; else w /= 2;
        p = 0;
        int j = 1;
        S.clear();
        add(w - a[i]);
        add(w - a[2]);
        add(w - a[1]);
        while (j <= n*(n-1)/2) {
            if (S.empty() || *S.begin() > a[j]) add(a[j] - b[1]);
            if (*S.begin() == a[j]) ++j, S.erase(S.begin());
            else break;
        }
        if (j > n*(n-1)/2) break;
    }
    for(int i=1; i<=n; ++i) cout << b[i] << ' ';
}
