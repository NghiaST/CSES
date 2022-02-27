/// https://oeis.org/A060281
#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 5005, MOD = 1e9 + 7;
long long n, dp[N][N], AA[N][N], powern[N], f[N], f2[N], f3[N];
 
void Init() {
    f[0] = f[1] = f2[0] = f2[1] = f3[0] = f3[1] = 1;
    REP(i, 2, N) {
        f[i] = f[i-1] * i % MOD;
        f2[i] = MOD - MOD/i*f2[MOD%i] % MOD;
        f3[i] = f3[i-1] * f2[i] % MOD;
    }
    powern[0] = 1;
    FOR(i, 1, n) powern[i] = powern[i-1] * n % MOD;
}
 
long long C(int n, int k) {
    return f[n] * f3[k] % MOD * f3[n-k] % MOD;
}
 
void Process() {
    AA[0][0] = 1;
    FOR(i, 1, n) FOR(j, 1, i) AA[i][j] = (AA[i-1][j-1] - (i-1) * AA[i-1][j]) % MOD;
    FOR(k, 1, n) {
        long long res = 0;
        REP(j, 0, n)
            (res += C(n-1, j) * powern[n-1-j] % MOD * ((k+j+1)&1 ? -1 : 1) % MOD * AA[j+1][k] % MOD) %= MOD;
        res = (res + MOD) % MOD;
        cout << res << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    Init();
    Process();
}
