#include <iostream>
using namespace std;
const int N = 3005;
int n, k, lft, rgt;
long long a[N], dp[N], dp2[N];
struct Data{
    long long x, y;
    long long get(long long val) {
        return x * val + y;
    }
} Q[N];
 
bool check(Data a, Data b, Data c) {
    return (a.y - b.y) * (c.x - a.x) >= (b.x - a.x) * (a.y - c.y);
}
 
void update(int u) {
    Data w = {-2 * a[u], dp2[u] + a[u] * a[u]};
    while (rgt > lft && check(Q[rgt - 1], Q[rgt], w)) --rgt;
    Q[++rgt] = w;
}
 
long long query(long long val) {
    while (rgt > lft && Q[lft].get(val) >= Q[lft+1].get(val)) ++lft;
    return Q[lft].get(val);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i], a[i] += a[i-1];
    for(int i=1; i<=n; ++i) dp[i] = a[i] * a[i];
    for(int i=2; i<=k; ++i) {
        lft = 1, rgt = 0;
        for(int j=i-1; j<=n; ++j) dp2[j] = dp[j];
        update(i-1);
        for(int j=i; j<=n; ++j) {
            dp[j] = query(a[j]) + a[j] * a[j];
            update(j);
        }
    }
    cout << dp[n];
}
