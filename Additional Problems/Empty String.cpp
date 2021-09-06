#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1e9 + 7;
long long n, C[505][505], f[505][505];
char s[505];
 
int main()
{
    cin >> s+1; n = strlen(s+1);
    C[0][0] = 1;
    for(int i=1; i*2<=n; ++i) {
        C[i][0] = 1;
        for(int j=1; j<=i; ++j) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
    for(int i=1; i<=n+1; ++i) f[i][i-1] = 1;
 
    for(int j=1; j<=n; ++j)
    for(int i=j-1; i>0; i-=2) {
        for(int w=i+1; w<=j; ++w) if (s[w] == s[i])
            (f[i][j] += f[i+1][w-1] * f[w+1][j] % MOD * C[(j-i+1)/2][(w-i+1)/2]) %= MOD;
    }
    cout << f[1][n];
}
