#include <iostream>
using namespace std;
const int N = 505, MOD = 1e9 + 7;
int n, k, f[N*N], sum[N*N];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    f[0] = 1;
    for(int i=2; i<=n; ++i) {
        sum[0] = f[0];
        for(int j=1; j<=i*(i-1)/2; ++j) sum[j] = (sum[j-1] + f[j]) % MOD;
        for(int j=0; j<=i*(i-1)/2; ++j) {
            f[j] = sum[j];
            if (j >= i) f[j] = (f[j] - sum[j-i] + MOD) % MOD;
        }
    }
    cout << f[k];
}
