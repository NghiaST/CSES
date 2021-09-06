#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;
int n, m;
long long res, ans[1005], f[N*2], f2[N*2], f3[N*2];
struct Data{
    int x, y;
    bool operator < (Data &p) { return y < p.y || y == p.y && x < p.x; }
} a[1005];
 
void Init() {
    f[0] = f[1] = f2[0] = f2[1] = f3[0] = f3[1] = 1;
    for(int i=2; i<=n*2; ++i) {
        f[i] = f[i-1] * i % MOD;
        f2[i] = MOD - MOD / i * f2[MOD % i] % MOD;
        f3[i] = f3[i-1] * f2[i] % MOD;
    }
}
 
long long C(int n, int k) {
    return f[n] * f3[k] % MOD * f3[n - k] % MOD;
}
 
long long get(int x, int y) {
    return C(x + y - 2, x - 1);
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    Init();
    for(int i=1; i<=m; ++i) cin >> a[i].x >> a[i].y;
    sort(a+1, a+m+1);
    res = get(n, n);
    for(int i=1; i<=m; ++i) {
        ans[i] = get(a[i].x, a[i].y);
        for(int j=1; j<i; ++j) if (a[j].x <= a[i].x)
            ans[i] = (ans[i] + MOD - ans[j] * get(a[i].x - a[j].x + 1, a[i].y - a[j].y + 1) % MOD) % MOD;
        res = (res - ans[i] * get(n - a[i].x + 1, n - a[i].y + 1) % MOD + MOD) % MOD;
    }
    cout << res;
}
