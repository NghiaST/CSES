/// DP on Broken Profile
#include <iostream>
#include <algorithm>
#define getBIT(x,i) ((x>>(i))&1)
#define xorBIT(x,i) (x ^ (1<<(i)))
using namespace std;
const int N = 1024, MOD = 1e9 + 7;
int n, m, f[N], f2[N];
 
void Enter() {
    cin >> n >> m;
}
 
void Process() {
    f[0] = 1;
    for(int j=1; j<=m; ++j) {
        for(int i=0; i<n; ++i) {
            for(int tt=0; tt<(1<<n); ++tt) f2[tt] = f[tt];
            for(int tt=0; tt<(1<<n); ++tt) {
                f[tt] = f2[xorBIT(tt, i)];
                if (i && !getBIT(tt, i) && !getBIT(tt, i-1))
                    f[tt] = (f[tt] + f2[xorBIT(tt, i-1)]) % MOD;
            }
        }
    }
    cout << f[0];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
