#include <iostream>
using namespace std;
int t, n, l, r, a[200005], b[200005], Q[200005];
long long f[200005];
 
long long get(int x, int val) {
    return f[x] + 1LL * b[x] * val;
}
 
long double giao(int i, int j) {
    return (f[i] - f[j]) / (b[j] - b[i]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> b[0];
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=n; ++i) cin >> b[i];
    l = r = 1; Q[r] = 0;
    for(int i=1; i<=n; ++i) {
        while (l < r && get(Q[l], a[i]) >= get(Q[l+1], a[i])) ++l;
        f[i] = get(Q[l], a[i]);
        while (r > l && giao(Q[r-1], Q[r]) >= giao(Q[r-1], i)) --r;
        if (b[i] != b[Q[r]]) Q[++r] = i;
    }
    cout << f[n];
}
