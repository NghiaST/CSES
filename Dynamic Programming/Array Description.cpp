#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, res, a[100005], f[100005][2];
 
void Enter() {
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> a[i];
}
 
void Process() {
    if (a[1] == 0) for(int i=1; i<=m; ++i) f[i][0] = 1;
    else f[a[1]][0] = 1;
    int ok = 0;
    for(int i=2; i<=n; ++i) {
        ok ^= 1;
        if (a[i] == 0) {
            for(int j=1; j<=m; ++j) f[j][ok] = ((f[j-1][ok^1] + f[j][ok^1]) % MOD + f[j+1][ok^1]) % MOD;
        }
        else {
            for(int j=1; j<=m; ++j) f[j][ok] = 0;
            f[a[i]][ok] = ((f[a[i] - 1][ok^1] + f[a[i]][ok^1]) % MOD + f[a[i] + 1][ok^1]) % MOD;
        }
    }
    for(int i=1; i<=m; ++i) res = (res + f[i][ok]) % MOD;
    cout << res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
