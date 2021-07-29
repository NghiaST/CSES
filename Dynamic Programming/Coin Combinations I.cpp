#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int n, m, x, a[105], f[1000005];
 
void Enter() {
    cin >> n >> m;
}
 
void Process() {
    f[0] = 1;
    for(int i=1; i<=n; ++i) cin >> a[i];
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j)
            if (i >= a[j]) f[i] = (f[i] + f[i-a[j]]) % MOD;
    }
    cout << f[m];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
