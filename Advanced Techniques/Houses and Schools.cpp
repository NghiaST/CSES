#include <iostream>
using namespace std;
const int N = 3005;
int n, k, a[N];
long long res, lft[N][N], rgt[N][N], dp[N], dp2[N];
 
long long get(int l, int r) {
    int mid = (l+r) / 2;
    return rgt[l][mid] + lft[mid+1][r];
}
 
void solve(int l, int r, int itL, int itR) {
    if (l > r) return;
    int mid = (l + r) / 2;
    pair<long long, int> ans = {1e18, 0};
    for(int i = itL; i <= mid && i <= itR; ++i)
        ans = min(ans, {dp2[i] + get(i, mid), i});
    dp[mid] = ans.first;
    solve(l, mid-1, itL, ans.second);
    solve(mid+1, r, ans.second, itR);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
 
    for(int j=1; j<=n; ++j)
    for(int i=j; i; --i) lft[i][j] = lft[i+1][j] + 1LL * (j - i) * a[i];
    for(int i=n; i; --i)
    for(int j=i; j<=n; ++j) rgt[i][j] = rgt[i][j-1] + 1LL * (j - i) * a[j];
    for(int i=1; i<=n; ++i) dp[i] = lft[1][i];
 
    for(int i=2; i<=k; ++i) {
        for(int j=i-1; j<=n; ++j) dp2[j] = dp[j];
        solve(i, n, i-1, n);
    }
    res = 1e18;
    for(int i=k; i<=n; ++i) res = min(res, dp[i] + rgt[i][n]);
    cout << res;
}
