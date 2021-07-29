#include <iostream>
#include <cstring>
using namespace std;
const int N = 505, MOD = 1e9 + 7;
int n, f[N*N];
 
void Enter() {
    cin >> n;
}
 
void Process() {
    f[0] = 1;
    if (n*(n+1) % 4 != 0) return (void) (cout << 0);
    for(int i=1; i<=n; ++i)
        for(int j=n*(n+1)/4; j>=i; --j)
            f[j] = (f[j] + f[j-i]) % MOD;
    cout << f[n*(n+1)/4] * 1LL * ((MOD + 1) / 2) % MOD;
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
