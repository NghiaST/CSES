#include <iostream>
#include <cstring>
using namespace std;
const int N = 500005, MOD = 1e9 + 7;
int n, dp[N], prv[26];
char s[N];
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> s + 1; n = strlen(s+1);
    dp[0] = 1;
    for(int i=1; i<=n; ++i) {
        dp[i] = dp[i-1] * 2 % MOD;
        int w = s[i] - 'a';
        if (prv[w] > 0) dp[i] = (dp[i] + MOD - dp[prv[w] - 1]) % MOD;
        prv[w] = i;
    }
    cout << (dp[n] + MOD - 1) % MOD;
}
