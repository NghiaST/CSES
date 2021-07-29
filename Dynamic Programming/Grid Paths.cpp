#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
int n, f[1005][1005];
char s[1005][1005];
 
void Enter() {
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> s[i] + 1;
}
 
void Process() {
    f[0][1] = 1;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            if (s[i][j] == '.')
                f[i][j] = (f[i-1][j] + f[i][j-1]) % MOD;
        }
    }
    cout << f[n][n];
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
