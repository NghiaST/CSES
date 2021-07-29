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
    for(int i=1; i<=n; ++i) {
        cin >> x;
        for(int j=x; j<=m; ++j) f[j] = (f[j] + f[j-x]) % MOD;
    }
    cout << f[m];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
